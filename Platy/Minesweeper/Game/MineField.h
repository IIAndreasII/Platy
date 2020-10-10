#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Platy.Game.Core/Postmaster/Subscriber.h"

constexpr unsigned int DEFAULT_FRAME_THICKNESS = 16;

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
typedef Tile* TilePtr;

using namespace Platy::Game;

class MineField final : public sf::Drawable, public Subscriber
{
public:
	enum class ESize
	{
		EASY,
		INTERMEDIATE,
		HARD
	};

	enum class EState
	{
		SWEEPING,
		GAME_OVER,
		VICTORY
	};

	explicit MineField(ESize aSize, sf::Vector2i offset = sf::Vector2i(16, 16));
	~MineField() override;

	///////////////////////////////
	// GET
	///////////////////////////////

	unsigned GetElapsedSeconds() const;

	const uint8_t& GetNbrMinesLeft() const;

	///////////////////////////////

	void ReceiveMessage(const EMessageType& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) override;

	void Update(const float& deltaTime);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	sf::Vector2i myOffset;
	sf::Sprite myFrame;

	std::vector<std::vector<Tile>> myMineField;

	std::vector<TilePtr> myMinePointers;

	//ESize mySize;
	EState myState;

	uint8_t myNbrCols;
	uint8_t myNbrRows;
	uint8_t myNbrMines;
	uint8_t myNbrMinesLeft;

	float myElapsedTime;
	float myMineExplosionDelay;
	float myExplosionTimer;

	void GenerateField(uint8_t cols, uint8_t rows, uint8_t nbrMines);

	void PlaceMines(uint8_t nbrMines);

	void RevealTile(sf::Vector2i aPos, bool recursive = false);

	bool InRange(int col, int row) const;

	bool CheckVictory() const;

	sf::Vector2i ToMapPos(const sf::Vector2i& aWindowPos) const;
};

#endif
