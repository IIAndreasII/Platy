#include "Entity.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "..\Graphics\Animator.h"


Entity::~Entity()
{
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	myAnim->draw(target, states);
}

void Entity::SetPosition(const float& x, const float& y)
{
	sf::Transformable::setPosition(x, y);
}

const sf::Vector2f& Entity::GetPosition() const
{
	return sf::Transformable::getPosition();
}
