#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/Vector2.hpp"

class Animator2D;

typedef Animator2D* AnimatorPtr;

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	virtual ~Entity();

	virtual void Update(const float& deltaTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	void SetPosition(const float& x, const float& y);

	const sf::Vector2f& GetPosition() const;

protected:

	Animator2D* myAnim;

};

#endif