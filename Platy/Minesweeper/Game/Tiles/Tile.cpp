#include "Tile.h"

#include "Platy.Log/Log.h"
#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "Platy.Game.Core/Containers/AssetContainer.h"


Tile::Tile(const sf::Vector2i aPos) :
	myPos(aPos),
	myHasMine(false),
	myState(State::Unchecked),
	myCloseMineCount(0),
	mySprite()
{
	SetState(myState);
	mySprite.setPosition(sf::Vector2f(aPos));
}

Tile::~Tile()
{
}

const RevealInfo Tile::Reveal()
{
	SetState(State::Checked);
	return RevealInfo(myHasMine, myCloseMineCount);
}

void Tile::AddCloseMine()
{
	myCloseMineCount++;
}

void Tile::ToggleState()
{
	switch (myState)
	{
	case State::Unchecked:
		SetState(State::Flagged);
		break;
	case State::Flagged:
		SetState(State::Questioned);
		break;
	case Tile::State::Questioned:
		SetState(State::Unchecked);
		break;
	default:
		break;
	}
}

void Tile::Explode()
{
	if (myState != State::Flagged)
	{
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_mine_exploded"));
	}
}

void Tile::SetState(const State aNewState)
{
	switch (aNewState)
	{
	case State::Checked:
		if (!myHasMine)
		{
			mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_" + std::to_string(myCloseMineCount)));
		}
		else
		{
			switch (myState)
			{
			case State::Flagged:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_flagged_mine"));
				return;
			case State::Questioned:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_questioned_mine"));
				break;
			default:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_mine"));
				break;
			}
		}
		break;
	case State::Unchecked:
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_unchecked"));
		break;
	case State::Flagged:
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_flagged"));
		break;
	case State::Questioned:
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_questioned"));
		break;
	default:
		break;
	}
	myState = aNewState;
}

void Tile::PlaceMine()
{
	myHasMine = true;
}

const Tile::State& Tile::GetState() const
{
	return myState;
}

const uint8_t& Tile::GetCloseMineCount() const
{
	return myCloseMineCount;
}

const sf::Vector2i& Tile::GetPosition() const
{
	return myPos;
}

const bool& Tile::HasMine() const
{
	return myHasMine;
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;
	target.draw(mySprite);
}
