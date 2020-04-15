#include "pch.h"
#include "ParticleShower.h"
#include "ParticleFactory.h"
#include <cmath>
#include "Util.h"

ParticleShower::ParticleShower(const EOrientation anOrientation, sf::Vector2f aPosition, const sf::Color aColor, const float aLength, const float anIntensity, const float aFrequency, const float aLifeSpan, const int aMaxParticleSize, const float gravity, const float anEmissionAngle)
	: myOrientation(anOrientation),
	myLength(aLength),
	myIntensity(anIntensity),
	myFrequency(aFrequency),
	myEmissionAngle(anEmissionAngle),
	myParticleLifeSpan(aLifeSpan),
	myMaxParticleSize(aMaxParticleSize),
	mySpawnTimer(0),
	myPosition(aPosition)
{
	myColor = aColor;
	myIsActive = true;
	myGravity = gravity;
	myInensityModulation = myIntensity / INTENSITY_MODULATION_DIVISER;
}

ParticleShower::~ParticleShower()
{
}

void ParticleShower::Update(float& deltaTime)
{
	if (1.f / myFrequency < deltaTime)
	{
		for (size_t i = 0; i < deltaTime / (1.f / myFrequency); i++)
		{
			MakeParticle();
		}
	}
	else
	{
		mySpawnTimer -= deltaTime;
		if (mySpawnTimer <= 0)
		{
			MakeParticle();
			mySpawnTimer = 1.f / myFrequency;
		}
	}

	ParticleEmitter::Update(deltaTime);
}

void ParticleShower::Draw(sf::RenderWindow& aWindow)
{
	ParticleEmitter::Draw(aWindow);
}

void ParticleShower::MakeParticle()
{
	myParticles.push_back(
		ParticleFactory::CreateParticle(
			GetPosition(),
			GetVelocity() * (myIntensity + Util::RandFloat(-myInensityModulation, myInensityModulation)),
			sf::Color(myColor.r, myColor.g, myColor.b, myColor.a - Util::RandFloat(0, COLOR_MODULATION)),
			sf::Vector2f(Util::RandFloat(2, myMaxParticleSize), Util::RandFloat(2, myMaxParticleSize)),
			myParticleLifeSpan,
			myGravity));
}

const sf::Vector2f ParticleShower::GetPosition()
{
	switch (myOrientation)
	{
	case EOrientation::HORIZONTAL:
		return sf::Vector2f(myPosition.x + Util::RandFloat(0, myLength), myPosition.y);
	case EOrientation::HORIZONTAL_INVERTED:
		return sf::Vector2f(Util::RandFloat(myPosition.x, myPosition.x + myLength), myPosition.y);
	case EOrientation::VERTICAL:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	case EOrientation::VERTICAL_INVERTED:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	default:
		return myPosition;
	}
}

const sf::Vector2f ParticleShower::GetVelocity()
{
	float tempAngle;
	switch (myOrientation)
	{
	case EOrientation::HORIZONTAL:
		tempAngle = 180 - myEmissionAngle;
		break;
	case EOrientation::HORIZONTAL_INVERTED:
		tempAngle = 360 - myEmissionAngle;
		break;
	case EOrientation::VERTICAL:
		tempAngle = 90 - myEmissionAngle;
		break;
	case EOrientation::VERTICAL_INVERTED:
		tempAngle = 270 - myEmissionAngle;
		break;
	}
	return Util::DegToVec2(tempAngle);
}
