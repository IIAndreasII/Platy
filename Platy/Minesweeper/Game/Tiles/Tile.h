#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Platy.Game.Core/Postmaster/Subscriber.h"

struct RevealInfo
{
public:
	RevealInfo(const bool& mine, const uint8_t& aCloseMineCount) : 
		isMine(mine), 
		closeMineCount(aCloseMineCount) {};
	~RevealInfo() {};
	bool isMine;
	uint8_t closeMineCount;
};

class Tile : public sf::Drawable
{
public:
	Tile(const sf::Vector2i aPos);
	~Tile();

	enum class State
	{
		Checked,
		Unchecked,
		Flagged,
		Questioned,
	};


	const RevealInfo Reveal();

	void AddCloseMine();

	void ToggleState();

	void Explode();

	/////////////////
	// SET
	/////////////////
	void SetState(const State aNewState);

	/// <summary>
	/// Use only during minefield creation!
	/// </summary>
	void PlaceMine();

	/////////////////
	// GET
	/////////////////
	const State& GetState() const;

	const uint8_t& GetCloseMineCount() const;

	const sf::Vector2i& GetPosition() const;

	const bool& HasMine() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:

	sf::Sprite mySprite;

	sf::Vector2i myPos;

	uint8_t myCloseMineCount;

	bool myHasMine;

	State myState;

};

#endif