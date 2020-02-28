#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Move(float& x, float& y)
{
	myPosition = sf::Vector2f(x, y);
}
