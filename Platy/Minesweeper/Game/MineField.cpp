#include "MineField.h"
#include "Tiles/Tile.h"

#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Postmaster/Message.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"

MineField::MineField(const Size aSize) :
	mySize(aSize),
	myGameOverFlag(false)
{
	Subscribe(Message::Type::MOUSE_ON_CLICK_LEFT);
	Subscribe(Message::Type::MOUSE_ON_CLICK_RIGHT);

	GenerateField(aSize);
}

MineField::~MineField()
{
	RemoveAllSubscriptions();
}

const bool& MineField::IsGameOver() const
{
	return myGameOverFlag;
}

void MineField::ReceiveMessage(const Message::Type& aMessageType)
{
}

void MineField::ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType)
{
	if (myGameOverFlag)
	{
		return;
	}

	sf::Vector2i pos = ToMapPos(aMessage.GetPosition());
	switch (aMessageType)
	{
	case Message::Type::MOUSE_ON_CLICK_LEFT:

		if (myMineField.at(pos.x).at(pos.y).GetState() == Tile::State::Unchecked)
		{
			RevealTile(pos);
		}
		else if (aMessage.GetBool() && myMineField.at(pos.x).at(pos.y).GetState() == Tile::State::Checked)
		{
			int closeFlagCount = 0;

			for (int c = -1; c <= 1; c++)
			{
				for (int r = -1; r <= 1; r++)
				{
					if ((pos.x + c != pos.x || pos.y + r != pos.y) && InRange(pos.x + c, pos.y + r))
					{
						if (myMineField.at(pos.x + c).at(pos.y + r).GetState() == Tile::State::Flagged)
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
							if (myMineField.at(pos.x + c).at(pos.y + r).GetState() == Tile::State::Unchecked)
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
		break;
	default:
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
}

void MineField::GenerateField(const Size aSize)
{
	// Setup
	switch (aSize)
	{
	case MineField::Size::Easy:
		myNbrCols = myNbrRows = COLS_EASY;
		myNbrMines = MINES_EASY;
		break;

	case MineField::Size::Intermediate:
		myNbrCols = myNbrRows = COLS_INTERMEDIATE;
		myNbrMines = MINES_INTERMEDIATE;
		break;
	case MineField::Size::Hard:
		myNbrCols = COLS_HARD;
		myNbrRows = ROWS_HARD;
		myNbrMines = MINES_HARD;
		break;
	}

	// Create tilemap
	for (size_t i = 0; i < myNbrCols; i++)
	{
		myMineField.push_back(std::vector<Tile>());
		for (size_t j = 0; j < myNbrRows; j++)
		{
			myMineField.at(i).push_back(Tile(sf::Vector2i(i, j) * 32));
		}
	}

	// Randomize mine positions
	for (size_t i = 0; i < myNbrMines; i++)
	{
		int row = Platy::Core::Util::RandInt(0, myNbrRows);
		int col = Platy::Core::Util::RandInt(0, myNbrCols);
		
		while (myMineField.at(col).at(row).IsMine())
		{
			row = Platy::Core::Util::RandInt(0, myNbrRows);
			col = Platy::Core::Util::RandInt(0, myNbrCols);
		}
		
		myMineField.at(col).at(row).PlaceMine();

		// Add 1 minecount to neighbouring tiles
		for (int c = -1; c <= 1; c++)
		{
			for (int r = -1; r <= 1; r++)
			{
				if ((col + c != col || row + r != row) && InRange(col + c, row + r))
				{
					if (!myMineField.at(col + c).at(row + r).IsMine())
					{
						myMineField.at(col + c).at(row + r).AddCloseMine();
					}
				}
			}
		}
	}
}

void MineField::RevealTile(const sf::Vector2i aPos, const bool recursive)
{
	if (myMineField.at(aPos.x).at(aPos.y).GetState() == Tile::State::Unchecked)
	{
		RevealInfo info = myMineField.at(aPos.x).at(aPos.y).Reveal();

		if (info.isMine && !recursive)
		{
			for (size_t i = 0; i < myNbrCols; i++)
			{
				for (size_t j = 0; j < myNbrRows; j++)
				{
					Tile* tempTile = &myMineField.at(i).at(j);
					if (tempTile->IsMine())
					{
						tempTile->Reveal();
					}
				}
			}

			myGameOverFlag = true;
			SendMessage(Message::Type::GAME_OVER);
		}
		else if (info.closeMineCount == 0)
		{
			for (int c = -1; c <= 1; c++)
			{
				for (int r = -1; r <= 1; r++)
				{
					if ((aPos.x + c != aPos.x || aPos.y + r != aPos.y) && InRange(aPos.x + c, aPos.y + r))
					{
						if (myMineField.at(aPos.x + c).at(aPos.y + r).GetState() == Tile::State::Unchecked)
						{
							RevealTile(sf::Vector2i(aPos.x + c, aPos.y + r), true);
						}
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

const sf::Vector2i MineField::ToMapPos(const sf::Vector2i& aWindowPos) const
{
	return sf::Vector2i(aWindowPos.x / 32, aWindowPos.y / 32);
}
