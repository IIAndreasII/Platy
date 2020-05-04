#include "pch.h"
#include "Particle.h"
#include "Util.h"



/*Particle::Particle()
	: myPosition(),
	myVelocity(),
	myLifespan(),
	myGravity(),
	myShape(),
	myInitLifespan()
{
}*/

Particle::Particle(sf::Vector2f* aPosition, const sf::Vector2f aVelocity, const sf::Color &aColor, const sf::Vector2f aSize, const float& aLifespan, const float& gravity, const bool& shouldFade)
	: myPosition(*aPosition),
	myInitPosition(aPosition),
	myInitVelocity(aVelocity),
	myVelocity(aVelocity),
	myLifespan(aLifespan),
	myInitLifespan(aLifespan),
	myGravity(2 * gravity),
	myShape(aSize),
	myIsFading(shouldFade),
	myColor(aColor),
	myFadeRate(),
	myInitAlpha()
{
	if (shouldFade)
	{
		myFadeRate = aColor.a / aLifespan;
		myInitAlpha = aColor.a;
	}
	myShape.setFillColor(aColor);
	myShape.setPosition(myPosition);
}

Particle::~Particle()
{
}

void Particle::Update(float& deltaTime)
{
	if (myIsFading && myFadeRate * deltaTime < myColor.a)
	{
		myColor.a -= myFadeRate * deltaTime;
		myShape.setFillColor(myColor);
	}	

	myLifespan -= deltaTime;
	if (myLifespan <= 0)
	{
		Reset();
	}
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

void Particle::Reset()
{
	myPosition = *myInitPosition;
	myVelocity = myInitVelocity;
	myLifespan = myInitLifespan;
	if (myIsFading) 
	{
		myColor.a = myInitAlpha;
	}
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

const bool Particle::GetAlive() const
{
	return myLifespan > 0;
}
