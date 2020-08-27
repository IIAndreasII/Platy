#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <vector>
#include "SFML/Graphics/Drawable.hpp"
#include "Platy.Game.Core/Postmaster/Subscriber.h"

constexpr uint8_t COLS_EASY = 9;
constexpr uint8_t COLS_INTERMEDIATE = 16;
constexpr uint8_t COLS_HARD = 30;
constexpr uint8_t ROWS_HARD = 16;

constexpr uint8_t MINES_EASY = 10;
constexpr uint8_t MINES_INTERMEDIATE = 40;
constexpr uint8_t MINES_HARD = 99;

class Tile;

class MineField : public sf::Drawable, public Subscriber
{
public:
	enum class Size
	{
		Easy,
		Intermediate,
		Hard
	};
	
	MineField(const Size aSize);
	~MineField();


	const bool& IsGameOver() const;

	void ReceiveMessage(const Message::Type& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType) override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::Vector2f myTopLeftPos;

	std::vector<std::vector<Tile>> myMineField;

	Size mySize;

	uint8_t myNbrCols;
	uint8_t myNbrRows;
	uint8_t myNbrMines;

	bool myGameOverFlag;

	void GenerateField(const Size aSize);

	void RevealTile(const sf::Vector2i aPos, const bool recursive = false);

	const bool InRange(const int col, const int row) const;

	const sf::Vector2i ToMapPos(const sf::Vector2i& aWindowPos) const;

};

#endif