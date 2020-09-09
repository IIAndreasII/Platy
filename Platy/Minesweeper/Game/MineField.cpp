#include "MineField.h"
#include "Tiles/Tile.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Containers/AssetContainer.h"
#include "Platy.Game.Core/Factories/ParticleEmitterFactory.h"


MineField::MineField(const Size aSize, const sf::Vector2i offset) :
	myOffset(offset),
	mySize(aSize),
	myMineField(),
	myMinePtrs(),
	myNbrCols(),
	myNbrRows(),
	myNbrMines(),
	myNbrMinesLeft(),
	myMineExplosionDelay(.02f),
	myExplosionTimer(),
	myState(EState::Sweeping),
	myElapsedTime(),
	myFrame()
{
	Subscribe(Message::Type::MOUSE_ON_CLICK_LEFT);
	Subscribe(Message::Type::MOUSE_ON_CLICK_RIGHT);

	myFrame.setPosition(sf::Vector2f(offset - sf::Vector2i(DEFAULT_FRAME_THICKNESS, DEFAULT_FRAME_THICKNESS)));
	switch (aSize)
	{
	case Size::Easy:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_easy"));
		GenerateField(COLS_EASY, ROWS_EASY, MINES_EASY);
		break;
	case Size::Intermediate:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_intermediate"));
		GenerateField(COLS_INTERMEDIATE, ROWS_INTERMEDIATE, MINES_INTERMEDIATE);
		break;
	case Size::Hard:
		myFrame.setTexture(*AssetContainer::GetTexturePtr("frame_hard"));
		GenerateField(COLS_HARD, ROWS_HARD, MINES_HARD);
		break;
	}
}

MineField::~MineField()
{
	RemoveAllSubscriptions();
	for (TilePtr it : myMinePtrs)
	{
		it = NULL;
	}
}

const unsigned MineField::GetElapsedSeconds() const
{
	return (unsigned)myElapsedTime;
}

const uint8_t& MineField::GetNbrMinesLeft() const
{
	return myNbrMinesLeft;
}

void MineField::ReceiveMessage(const Message::Type& aMessageType)
{
}

void MineField::ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType)
{
	if (myState != EState::Sweeping)
	{
		return;
	}

	sf::Vector2i pos = ToMapPos(aMessage.GetPosition());
	switch (aMessageType)
	{
	case Message::Type::MOUSE_ON_CLICK_LEFT:

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
						if (myMineField.at((size_t)pos.x + c).at((size_t)pos.y + r).GetState() == Tile::EState::Flagged)
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
							if (myMineField.at((size_t)pos.x + c).at((size_t)pos.y + r).GetState() == Tile::EState::Unchecked)
							{
								RevealTile(sf::Vector2i(pos.x + c, pos.y + r));
							}
						}
					}
				}
			}
		}
		
		break;

	case Message::Type::MOUSE_ON_CLICK_RIGHT:
		myMineField.at(pos.x).at(pos.y).ToggleState();

		switch (myMineField.at(pos.x).at(pos.y).GetState())
		{
		case Tile::EState::Flagged:
			if (myNbrMinesLeft > 0)
			{
				myNbrMinesLeft--;
			}

			SendMessage(Message::Type::TILE_FLAGGED);

			if (CheckVictory())
			{
				for (size_t col = 0; col < myMineField.size(); col++)
				{
					for (size_t row = 0; row < myMineField.at(col).size(); row++)
					{
						if (myMineField.at(col).at(row).GetState() == Tile::EState::Unchecked || myMineField.at(col).at(row).GetState() == Tile::EState::Flagged)
						{
							myMineField.at(col).at(row).Reveal();
						}
					}
				}
				myState = EState::Victory;
				SendMessage(Message::Type::VICTORY);
			}
			break;
		case Tile::EState::Questioned:
			if (myNbrMinesLeft < myNbrMines)
			{
				myNbrMinesLeft++;
			}
			SendMessage(Message::Type::TILE_UNFLAGGED);
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
	case EState::GameOver:
		myExplosionTimer -= deltaTime;
		if (myExplosionTimer <= 0 && myMinePtrs.size() > 0)
		{
			myExplosionTimer = myMineExplosionDelay;
			sf::Vector2i pos = myMinePtrs.at(myMinePtrs.size() - 1)->GetPosition() + sf::Vector2i(DEFAULT_TILE_SIZE / 2, DEFAULT_TILE_SIZE / 2);
			
			myMinePtrs.at(myMinePtrs.size() - 1)->Explode();
			myMinePtrs.at(myMinePtrs.size() - 1) = NULL;
			myMinePtrs.pop_back();

			ParticleEmitterFactory::CreateExplosion(4, sf::Vector2f(pos), C_YELLOW,   200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosion(4, sf::Vector2f(pos), C_ORANGE,   200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosion(4, sf::Vector2f(pos), C_RED,      200, 200, .5f, false, 9.82f * 2);
			ParticleEmitterFactory::CreateExplosion(4, sf::Vector2f(pos), C_RED_DARK, 200, 200, .5f, false, 9.82f * 2);
		}
		break;
	case EState::Victory:
		break;
	default:
		myElapsedTime += deltaTime;
		break;
	}
}

void MineField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;
	for (auto col : myMineField)
	{
		for (auto tile : col)
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
		myMineField.push_back(std::vector<Tile>());
		for (size_t j = 0; j < myNbrRows; j++)
		{
			myMineField.at(i).push_back(Tile(sf::Vector2i((int)i, (int)j) * 32 + myOffset));
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
		myMinePtrs.push_back(&myMineField.at(col).at(row));

		// Add 1 minecount to neighbouring tiles
		for (int c = -1; c <= 1; c++)
		{
			for (int r = -1; r <= 1; r++)
			{
				if ((col + c != col || row + r != row) && InRange(col + c, row + r))
				{
					if (!myMineField.at((size_t)col + c).at((size_t)row + r).HasMine())
					{
						myMineField.at((size_t)col + c).at((size_t)row + r).AddCloseMine();
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
		Tile::RevealInfo info = myMineField.at(aPos.x).at(aPos.y).Reveal();

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
			for (size_t i = myMinePtrs.size(); i > 0; i--)
			{
				if (myMinePtrs.at(i - 1)->GetState() == Tile::EState::Flagged)
				{
					myMinePtrs.at(i - 1) = NULL;
					myMinePtrs.erase(myMinePtrs.begin() + i - 1);
				}
			}
			myState = EState::GameOver;
			SendMessage(Message::Type::GAME_OVER);
		}
		else if (info.closeMineCount == 0)
		{
			for (int c = -1; c <= 1; c++)
			{
				for (int r = -1; r <= 1; r++)
				{
					if ((aPos.x + c != aPos.x || aPos.y + r != aPos.y) &&
						InRange(aPos.x + c, aPos.y + r) &&
						myMineField.at((size_t)aPos.x + c).at((size_t)aPos.y + r).GetState() == Tile::EState::Unchecked)
					{
						RevealTile(sf::Vector2i(aPos.x + c, aPos.y + r), true);
					}
				}
			}
		}
	}
}

const bool MineField::InRange(const int col, const int row) const
{
	return col >= 0 && col < myNbrCols && row >= 0 && row < myNbrRows;
}

const bool MineField::CheckVictory() const
{
	for (TilePtr it : myMinePtrs)
	{
		if (it->GetState() != Tile::EState::Flagged)
		{
			return false;
		}
	}
	return true;
}

const sf::Vector2i MineField::ToMapPos(const sf::Vector2i& aWindowPos) const
{
	return sf::Vector2i((aWindowPos.x - myOffset.x) / DEFAULT_TILE_SIZE, (aWindowPos.y - myOffset.y) / DEFAULT_TILE_SIZE);
}
