#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

class Entity
{
public:
	Entity();
	~Entity();

	virtual void Update(const float& deltaTime) = 0;
	virtual void Draw(sf::RenderWindow& aWindow) = 0;

protected:

	void Move(float& x, float& y);
	sf::Vector2f myPosition;


private:


};

#endif