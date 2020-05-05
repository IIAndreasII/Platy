#include "ParticleExplosion.h"
#include "ParticleFactory.h"
#include "Util.h"
#include <iostream>



ParticleExplosion::ParticleExplosion(sf::Vector2f* aPosition, const sf::Color& aColor, const unsigned& nbrOfParticles, const float& aParticleMaxSize, const float& anIntensity, const float& gravity, const float& aLifeSpan, const bool &shouldParticlesFade)
	: myLifespan(aLifeSpan)
{
	myIsActive = true;
	myInensityModulation = anIntensity / INTENSITY_MODULATION_DIVISER_EXPLOSION;
	for (size_t i = 0; i < nbrOfParticles; i++)
	{
		float tempAngle = Util::RandFloat(0, 360);
		myParticles.push_back(ParticleFactory::CreateParticle(
			aPosition,
			Util::DegToVec2(tempAngle) * (anIntensity + Util::RandFloat(-myInensityModulation, myInensityModulation)),
			aColor,
			sf::Vector2f(Util::RandFloat(2, aParticleMaxSize), Util::RandFloat(2, aParticleMaxSize)),
			aLifeSpan,
			gravity,
			shouldParticlesFade));
	}
}

ParticleExplosion::~ParticleExplosion()
{
}

void ParticleExplosion::Update(float& deltaTime)
{
	myLifespan -= deltaTime;
	if (myLifespan <= 0)
	{
		myIsActive = false;
	}
	ParticleEmitter::Update(deltaTime);
}

void ParticleExplosion::Draw(sf::RenderWindow& aWindow)
{
	ParticleEmitter::Draw(aWindow);
}

const bool& ParticleExplosion::GetActive() const
{
	return myIsActive;
}

void ParticleExplosion::MakeParticle()
{
}
