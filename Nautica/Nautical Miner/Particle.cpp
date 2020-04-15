#include "pch.h"
#include "Particle.h"
#include "Util.h"



Particle::Particle()
	: myPosition(),
	myVelocity(),
	myLifespan(),
	myGravity(),
	myShape()
{
}

Particle::Particle(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color &aColor, const sf::Vector2f aSize, const float aLifespan, const float gravity)
	: myPosition(aPosition),
	myVelocity(aVelocity),
	myLifespan(aLifespan),
	myGravity(2 * gravity),
	myShape(aSize)
{
	myShape.setFillColor(aColor);
	myShape.setPosition(myPosition);
}

Particle::~Particle()
{
}

void Particle::Update(float& deltaTime)
{
	myLifespan -= deltaTime;
	if (myGravity != 0)
	{
		myVelocity.y += myGravity * myGravity * deltaTime;
	}
	myPosition += myVelocity * deltaTime;
	myShape.setPosition(myPosition);
}

void Particle::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(myShape);
	
}

inline void Particle::SetTraits(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color& aColor, const sf::Vector2f aSize, const float aLifespan, const bool useGravity)
{
	myPosition = aPosition;
	myVelocity = aVelocity;
	myShape.setSize(aSize);
	myShape.setFillColor(aColor);
	myLifespan = aLifespan;
	myGravity = useGravity;
}

const bool Particle::GetAlive()
{
	return myLifespan > 0;
}
