#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::SetPosition(float& x, float& y)
{
	myPosition = sf::Vector2f(x, y);
}

const sf::Vector2f& Entity::GetPosition()
{
	return myPosition;
}
