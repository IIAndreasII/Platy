#include "MineField.h"

#include "Graphics/Colors.h"
#include "Tiles/Tile.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Containers/AssetContainer.h"
#include "Platy.Game.Core/Graphics/Factories/ParticleEmitterFactory.h"

using namespace Platy::Game;
using namespace Graphics;

MineField::MineField(const ESize aSize, const sf::Vector2i offset) :
	myOffset(offset),
	mySize(aSize),
	myState(EState::SWEEPING),
	myNbrCols(),
	myNbrRows(),
	myNbrMines(),
	myNbrMinesLeft(),
	myElapsedTime(),
	myMineExplosionDelay(.02f),
	myExplosionTimer()
{
	Subscribe(Message::EType::MOUSE_ON_CLICK_LEFT);
	Subscribe(Message::EType::MOUSE_ON_CLICK_RIGHT);

	myFrame.setPosition(sf::Vector2f(offset - sf::Vector2i(DEFAULT_FRAME_THICKNESS, DEFAULT_FRAME_THICKNESS)));
	switch (aSize)
	{
	case ESize::EASY:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_easy"));
		GenerateField(COLS_EASY, ROWS_EASY, MINES_EASY);
		break;
	case ESize::INTERMEDIATE:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_intermediate"));
		GenerateField(COLS_INTERMEDIATE, ROWS_INTERMEDIATE, MINES_INTERMEDIATE);
		break;
	case ESize::HARD:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_hard"));
		GenerateField(COLS_HARD, ROWS_HARD, MINES_HARD);
		break;
	}
}

MineField::~MineField()
{
	RemoveAllSubscriptions();
	for (TilePtr it : myMinePointers)
	{
		it = nullptr;
	}
}

unsigned MineField::GetElapsedSeconds() const
{
	return static_cast<unsigned>(myElapsedTime);
}

const uint8_t& MineField::GetNbrMinesLeft() const
{
	return myNbrMinesLeft;
}

void MineField::ReceiveMessage(const Message::EType& aMessageType)
{
}

void MineField::ReceiveMessage(const Message& aMessage, const Message::EType& aMessageType)
{
	if (myState != EState::SWEEPING)
	{
		return;
	}

	sf::Vector2i pos = ToMapPos(aMessage.GetPosition());
	switch (aMessageType)
	{
	case Message::EType::MOUSE_ON_CLICK_LEFT:

		if (myMineField.at(pos.x).at(pos.y).GetState() == Tile::EState::Unchecked)
		{
			RevealTile(pos);
		}
		else if (aMessage.GetBool() && myMineField.at(pos.x).at(pos.y).GetState() == Tile::EState::Checked)
		{
			int closeFlagCount = 0;

			for (int c = -1; c <= 1; c++)
			{
				for (int r = -1; r <= 1; r++)
				{
					if ((pos.x + c != pos.x || pos.y + r != pos.y) && InRange(pos.x + c, pos.y + r))
					{
						if (myMineField.at(static_cast<size_t>(pos.x) + c).at(static_cast<size_t>(pos.y) + r).GetState()
							== Tile::EState::Flagged)
						{
							closeFlagCount++;
						}
					}
				}
			}

			if (closeFlagCount == myMineField.at(pos.x).at(pos.y).GetCloseMineCount())
			{
				for (int c = -1; c <= 1; c++)
				{
					for (int r = -1; r <= 1; r++)
					{
						if ((pos.x + c != pos.x || pos.y + r != pos.y) && InRange(pos.x + c, pos.y + r))
						{
							if (myMineField.at(static_cast<size_t>(pos.x) + c).at(static_cast<size_t>(pos.y) + r).
							                GetState() == Tile::EState::Unchecked)
							{
								RevealTile(sf::Vector2i(pos.x + c, pos.y + r));
							}
						}
					}
				}
			}
		}

		break;

	case Message::EType::MOUSE_ON_CLICK_RIGHT:
		myMineField.at(pos.x).at(pos.y).ToggleState();

		switch (myMineField.at(pos.x).at(pos.y).GetState())
		{
		case Tile::EState::Flagged:
			if (myNbrMinesLeft > 0)
			{
				myNbrMinesLeft--;
			}

			SendMessage(Message::EType::TILE_FLAGGED);

			if (CheckVictory())
			{
				for (size_t col = 0; col < myMineField.size(); col++)
				{
					for (size_t row = 0; row < myMineField.at(col).size(); row++)
					{
						if (myMineField.at(col).at(row).GetState() == Tile::EState::Unchecked || myMineField.at(col).
							at(row).GetState() == Tile::EState::Flagged)
						{
							myMineField.at(col).at(row).Reveal();
						}
					}
				}
				myState = EState::VICTORY;
				SendMessage(Message::EType::VICTORY);
			}
			break;
		case Tile::EState::Questioned:
			if (myNbrMinesLeft < myNbrMines)
			{
				myNbrMinesLeft++;
			}
			SendMessage(Message::EType::TILE_UN_FLAGGED);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void MineField::Update(const float& deltaTime)
{
	switch (myState)
	{
	case EState::GAME_OVER:
		myExplosionTimer -= deltaTime;
		if (myExplosionTimer <= 0 && !myMinePointers.empty())
		{
			myExplosionTimer = myMineExplosionDelay;
			const sf::Vector2i pos = myMinePointers.at(myMinePointers.size() - 1)->GetPosition() + sf::Vector2i(
				DEFAULT_TILE_SIZE / 2, DEFAULT_TILE_SIZE / 2);

			myMinePointers.at(myMinePointers.size() - 1)->Explode();
			myMinePointers.at(myMinePointers.size() - 1) = nullptr;
			myMinePointers.pop_back();

			ParticleEmitterFactory::CreateExplosionPtr(4, sf::Vector2f(pos), C_YELLOW, 200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosionPtr(4, sf::Vector2f(pos), C_ORANGE, 200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosionPtr(4, sf::Vector2f(pos), C_RED, 200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosionPtr(4, sf::Vector2f(pos), C_RED_DARK, 200, 200, .5f, false,
			                                           9.82f * 2);
		}
		break;
	case EState::VICTORY:
	case EState::SWEEPING:
		break;
	default:
		myElapsedTime += deltaTime;
		break;
	}
}

void MineField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = nullptr;
	for (const auto& col : myMineField)
	{
		for (const auto& tile : col)
		{
			target.draw(tile);
		}
	}
	target.draw(myFrame);
}

void MineField::GenerateField(const uint8_t cols, const uint8_t rows, const uint8_t nbrMines)
{
	myNbrCols = cols;
	myNbrRows = rows;

	for (size_t i = 0; i < myNbrCols; i++)
	{
		myMineField.emplace_back();
		for (size_t j = 0; j < myNbrRows; j++)
		{
			myMineField.at(i).emplace_back(sf::Vector2i(static_cast<int>(i), static_cast<int>(j)) * 32 + myOffset);
		}
	}

	PlaceMines(nbrMines);
}

void MineField::PlaceMines(const uint8_t nbrMines)
{
	myNbrMines = myNbrMinesLeft = nbrMines;

	for (size_t i = 0; i < myNbrMines; i++)
	{
		int row = Platy::Core::Util::RandInt(0, myNbrRows);
		int col = Platy::Core::Util::RandInt(0, myNbrCols);

		while (myMineField.at(col).at(row).HasMine())
		{
			row = Platy::Core::Util::RandInt(0, myNbrRows);
			col = Platy::Core::Util::RandInt(0, myNbrCols);
		}

		myMineField.at(col).at(row).PlaceMine();
		myMinePointers.push_back(&myMineField.at(col).at(row));

		// Add 1 mine count to neighboring tiles
		for (int c = -1; c <= 1; c++)
		{
			for (int r = -1; r <= 1; r++)
			{
				if ((col + c != col || row + r != row) && InRange(col + c, row + r))
				{
					if (!myMineField.at(static_cast<size_t>(col) + c).at(static_cast<size_t>(row) + r).HasMine())
					{
						myMineField.at(static_cast<size_t>(col) + c).at(static_cast<size_t>(row) + r).AddCloseMine();
					}
				}
			}
		}
	}
}

void MineField::RevealTile(const sf::Vector2i aPos, const bool recursive)
{
	if (myMineField.at(aPos.x).at(aPos.y).GetState() == Tile::EState::Unchecked)
	{
		const Tile::RevealInfo info = myMineField.at(aPos.x).at(aPos.y).Reveal();

		if (info.isMine && !recursive)
		{
			for (size_t i = 0; i < myNbrCols; i++)
			{
				for (size_t j = 0; j < myNbrRows; j++)
				{
					Tile* tempTile = &myMineField.at(i).at(j);
					if (tempTile->HasMine())
					{
						tempTile->Reveal();
					}
				}
			}

			// Make sure flagged mines don't explode
			for (size_t i = myMinePointers.size(); i > 0; i--)
			{
				if (myMinePointers.at(i - 1)->GetState() == Tile::EState::Flagged)
				{
					myMinePointers.at(i - 1) = nullptr;
					myMinePointers.erase(myMinePointers.begin() + i - 1);
				}
			}
			myState = EState::GAME_OVER;
			SendMessage(Message::EType::GAME_OVER);
		}
		else if (info.closeMineCount == 0)
		{
			for (int c = -1; c <= 1; c++)
			{
				for (int r = -1; r <= 1; r++)
				{
					if ((aPos.x + c != aPos.x || aPos.y + r != aPos.y) &&
						InRange(aPos.x + c, aPos.y + r) &&
						myMineField.at(static_cast<size_t>(aPos.x) + c).at(static_cast<size_t>(aPos.y) + r).GetState()
						== Tile::EState::Unchecked)
					{
						RevealTile(sf::Vector2i(aPos.x + c, aPos.y + r), true);
					}
				}
			}
		}
	}
}

bool MineField::InRange(const int col, const int row) const
{
	return col >= 0 && col < myNbrCols && row >= 0 && row < myNbrRows;
}

bool MineField::CheckVictory() const
{
	for (TilePtr it : myMinePointers)
	{
		if (it->GetState() != Tile::EState::Flagged)
		{
			return false;
		}
	}
	return true;
}

sf::Vector2i MineField::ToMapPos(const sf::Vector2i& aWindowPos) const
{
	return sf::Vector2i((aWindowPos.x - myOffset.x) / DEFAULT_TILE_SIZE,
	                    (aWindowPos.y - myOffset.y) / DEFAULT_TILE_SIZE);
}
