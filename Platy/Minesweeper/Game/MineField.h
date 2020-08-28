#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Platy.Game.Core/Postmaster/Subscriber.h"

constexpr uint8_t COLS_EASY = 9;
constexpr uint8_t ROWS_EASY = 9;
constexpr uint8_t COLS_INTERMEDIATE = 16;
constexpr uint8_t ROWS_INTERMEDIATE = 16;
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
	
	enum class State
	{
		Sweeping,
		GameOver,
		Victory
	};

	MineField(const Size aSize);
	~MineField();

	///////////////////////////////
	// GET
	///////////////////////////////

	const bool& IsGameOver() const;

	const int ElapsedSeconds() const;

	///////////////////////////////

	void ReceiveMessage(const Message::Type& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType) override;

	void Update(const float& deltaTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	sf::Vector2f myTopLeftPos;
	sf::Sprite myFrame;

	std::vector<std::vector<Tile>> myMineField;

	std::vector<Tile*> myMinePtrs;

	Size mySize;
	State myState;

	uint8_t myNbrCols;
	uint8_t myNbrRows;
	uint8_t myNbrMines;

	float myElapsedTime;
	float myMineExplosionDelay;
	float myExplosionTimer;

	bool myGameOverFlag;

	void GenerateField(const uint8_t cols, const uint8_t rows, const uint8_t nbrMines);

	void PlaceMines(const uint8_t nbrMines);

	void RevealTile(const sf::Vector2i aPos, const bool recursive = false);

	const bool InRange(const int col, const int row) const;

	const sf::Vector2i ToMapPos(const sf::Vector2i& aWindowPos) const;

};

#endif