#ifndef PARTICLE_H
#define PARTICLE_H

#include "Colors.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"


class Particle
{
public:

	Particle(sf::Vector2f* aPosition, 
			 const sf::Vector2f aVelocity, 
			 const sf::Color &aColor, 
			 const sf::Vector2f aSize, 
			 const float& aLifespan, 
			 const float& gravity,
			 const bool& shouldFade);
	~Particle();

	void Update(float& deltaTime);
	void Draw(sf::RenderWindow& aWindow);

	inline void Reset();

	const bool GetAlive() const;

private:

	const float myGravity;

	float myLifespan;
	const float myInitLifespan;
	const float myFadeRate;

	sf::RectangleShape myShape;

	sf::Vector2f myPosition;
	sf::Vector2f myVelocity;

	sf::Color myColor;
	const unsigned myInitAlpha;

	sf::Vector2f* myInitPosition;
	const sf::Vector2f myInitVelocity;

	const bool myIsFading;
};

#endif