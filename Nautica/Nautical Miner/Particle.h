#ifndef PARTICLE_H
#define PARTICLE_H

#include "Colors.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Particle
{
public:
	Particle();
	Particle(const sf::Vector2f& aPosition, 
			 const sf::Vector2f aVelocity, 
			 const sf::Color &aColor, 
			 const sf::Vector2f aSize, 
			 const float& aLifespan, 
			 const float& gravity);
	~Particle();

	void Update(float& deltaTime);
	void Draw(sf::RenderWindow& aWindow);

	void Reset();

	inline void SetTraits(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color& aColor, const sf::Vector2f aSize, const float aLifespan, const bool useGravity);

	const bool GetAlive();
	const sf::Vector2f GetPos();

private:

	float myGravity;

	float myLifespan;
	float myInitLifespan;

	sf::RectangleShape myShape;

	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;

	const sf::Vector2f myInitPosition;
	const sf::Vector2f myInitVelocity;
};

#endif