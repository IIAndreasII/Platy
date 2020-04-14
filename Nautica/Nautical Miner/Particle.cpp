#include "pch.h"
#include "Particle.h"
#include "Util.h"



Particle::Particle()
	: myPosition(),
	myVelocity(),
	myColor(),
	myLifespan(),
	myIsGravityAffected(),
	myShape()
{
}

Particle::Particle(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color &aColor, const sf::Vector2f dimensions, const float aLifespan, const bool useGravity)
	: myPosition(aPosition),
	myVelocity(aVelocity),
	myColor(aColor),
	myLifespan(aLifespan),
	myIsGravityAffected(useGravity),
	myShape(dimensions)
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
	if (myIsGravityAffected)
	{
		myVelocity.y += G * G * deltaTime;
	}
	myPosition += myVelocity * deltaTime;
	myShape.setPosition(myPosition);
}

void Particle::Draw(sf::RenderWindow& aWindow)
{
	aWindow.draw(myShape);
}

const bool Particle::GetAlive()
{
	return myLifespan > 0;
}
