#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Particle
{
public:
	Particle();
	Particle(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color &aColor, const sf::Vector2f aSize, const float aLifespan, const bool useGravity);
	~Particle();

	void Update(float& deltaTime);
	void Draw(sf::RenderWindow& aWindow);

	const bool GetAlive();

private:

	bool myIsGravityAffected;

	float myLifespan;

	sf::RectangleShape myShape;

	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;
	sf::Color myColor;
};

#endif