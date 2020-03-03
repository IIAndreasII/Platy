#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

class Animator2D;

typedef Animator2D* AnimatorPtr;

class Entity
{
public:
	~Entity();

	virtual void Update(const float& deltaTime) = 0;
	virtual void Draw(const sf::RenderWindow& aWindow) = 0;
	
	void SetPosition(float& x, float& y);

	const sf::Vector2f& GetPosition();

protected:
	Entity();


	sf::Vector2f myPosition;

	AnimatorPtr myAnim;



};

#endif