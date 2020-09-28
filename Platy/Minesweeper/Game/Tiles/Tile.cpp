#include "Tile.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Platy.Game.Core/Containers/AssetContainer.h"

Tile::Tile(const sf::Vector2i aPos) :
	myPos(aPos),
	myHasMine(false)
{
	SetState(myState);
	mySprite.setPosition(sf::Vector2f(aPos));
}

Tile::~Tile() = default;

Tile::RevealInfo Tile::Reveal()
{
	SetState(EState::Checked);
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
	case EState::Unchecked:
		SetState(EState::Flagged);
		break;
	case EState::Flagged:
		SetState(EState::Questioned);
		break;
	case EState::Questioned:
		SetState(EState::Unchecked);
		break;
	default:
		break;
	}
}

void Tile::Explode()
{
	if (myState != EState::Flagged)
	{
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_mine_exploded"));
	}
}

void Tile::SetState(const EState aNewState)
{
	switch (aNewState)
	{
	case EState::Checked:
		if (!myHasMine)
		{
			mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_" + std::to_string(myCloseMineCount)));
		}
		else
		{
			switch (myState)
			{
			case EState::Checked:
			case EState::Unchecked:
				break;
			case EState::Flagged:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_flagged_mine"));
				return;
			case EState::Questioned:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_questioned_mine"));
				break;
			default:
				mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_mine"));
				break;
			}
		}
		break;
	case EState::Unchecked:
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_unchecked"));
		break;
	case EState::Flagged:
		mySprite.setTexture(*AssetContainer::GetTexturePtr("tile_flagged"));
		break;
	case EState::Questioned:
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

const Tile::EState& Tile::GetState() const
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
	states.texture = nullptr;
	target.draw(mySprite);
}
