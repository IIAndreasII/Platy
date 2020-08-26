#include "Tile.h"

Tile::Tile() :
	myIsMine(false),
	myState(State::Unchecked),
	myCloseMineCount(0)
{
}

Tile::~Tile()
{
}

const uint8_t Tile::Reveal()
{
	// TODO: Reveal logic
	myState = State::Checked;

	return myCloseMineCount;
}

void Tile::AddCloseMine()
{
	myCloseMineCount++;
}

void Tile::SetState(const State aNewState)
{
	myState = aNewState;
}

const Tile::State& Tile::GetState() const
{
	return myState;
}

const bool& Tile::IsMine() const
{
	return myIsMine;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;



}
