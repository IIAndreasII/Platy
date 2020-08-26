#ifndef TILE_H
#define TILE_H

#include "SFML/Graphics/Drawable.hpp"
#include "Platy.Game.Core/Postmaster/Subscriber.h"

class Tile : public sf::Drawable, public Subscriber
{
public:
	Tile();
	~Tile();

	enum class State
	{
		Checked,
		Unchecked,
		Flagged,
		Questioned
	};


	const uint8_t Reveal();

	void AddCloseMine();

	/////////////////
	// SET
	/////////////////
	void SetState(const State aNewState);

	/////////////////
	// GET
	/////////////////
	const State& GetState() const;

	const bool& IsMine() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


private:

	uint8_t myCloseMineCount;

	bool myIsMine;

	State myState;

};

#endif