#include "pch.h"
#include "Util.h"
#include "Particle.h"
#include "ParticleFountain.h"
#include "ParticleFactory.h"
#include "Util.h"

constexpr float LIFESPAN_MIN = .5f;
constexpr float LIFESPAN_MAX = 2;


ParticleFountain::ParticleFountain(sf::Vector2f* aPosition, const sf::Color& aColor, const float& anEmissionAngle, const float& aSpreadAngle, const float& anIntensity, const float& aFrequency, const int& aMaxParticleSize, const float& gravity, const bool& shouldParticlesFade)
	: myEmissionAngle(anEmissionAngle),
	myColor(aColor),
	myIntensity(anIntensity),
	myFrequency(aFrequency),
	myMaxParticleSize(aMaxParticleSize),
	mySpreadAngle(aSpreadAngle),
	mySpawnTimer()
{
	myNbrOfParticles = LIFESPAN_MAX * aFrequency;
	myInensityModulation = myIntensity / INTENSITY_MODULATION_DIVISER_FOUNTAIN;
	myGravity = gravity;
	myIsActive = true;
	myPosition = aPosition;
	myShouldParticlesFade = shouldParticlesFade;
}

ParticleFountain::~ParticleFountain()
{
}

void ParticleFountain::Update(float& deltaTime)
{
	if (myParticles.size() < myNbrOfParticles)
	{
		mySpawnTimer -= deltaTime;
		if (mySpawnTimer <= 0)
		{
			MakeParticle();
			mySpawnTimer = 1.f / myNbrOfParticles;
		}
	}
	ParticleEmitter::Update(deltaTime);
}

void ParticleFountain::Draw(sf::RenderWindow& aWindow)
{
	ParticleEmitter::Draw(aWindow);
}

void ParticleFountain::SetPosition(sf::Vector2f* aPosition)
{
	myPosition = aPosition;
}

void ParticleFountain::MakeParticle()
{
	float tempAngle = Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle);
	myParticles.push_back(
		ParticleFactory::CreateParticle(
			myPosition,
			Util::DegToVec2(tempAngle) * (myIntensity + Util::RandFloat(-myInensityModulation, myInensityModulation)),
			sf::Color(myColor.r, myColor.g, myColor.b, myColor.a - Util::RandFloat(0, COLOR_MODULATION)),
			sf::Vector2f(Util::RandFloat(2, myMaxParticleSize), Util::RandFloat(2, myMaxParticleSize)),
			Util::RandFloat(LIFESPAN_MIN, LIFESPAN_MAX),
			myGravity,
			myShouldParticlesFade));
}
