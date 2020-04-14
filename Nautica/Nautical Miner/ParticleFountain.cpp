#include "pch.h"
#include "Util.h"
#include "Particle.h"
#include "ParticleFountain.h"
#include "ParticleFactory.h"


constexpr float LIFESPAN_MIN = .5f;
constexpr float LIFESPAN_MAX = 2;
constexpr float MODULATION = 150;
constexpr unsigned MAX_PARTICLES = 20;


ParticleFountain::ParticleFountain(sf::Vector2f* aPosition, const sf::Color aColor, const float anEmissionAngle, const float aSpreadAngle, const float anIntensity, const float aFrequency, const int aMaxParticleSize, const bool useGravity)
	: myEmissionAngle(anEmissionAngle),
	myColor(aColor),
	myIntensity(anIntensity),
	myFrequency(aFrequency),
	myMaxParticleSize(aMaxParticleSize),
	myUseGravity(useGravity),
	mySpreadAngle(aSpreadAngle),
	mySpawnTimer()
{
	myPosition = aPosition;
}

ParticleFountain::~ParticleFountain()
{
}

void ParticleFountain::Update(float& deltaTime)
{
	mySpawnTimer -= deltaTime;
	if (mySpawnTimer <= 0)
	{
		myParticles.push_back(ParticleFactory::CreateParticle(*myPosition,
			Util::DegToVec2(Util::ClampDeg(Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle))) * myIntensity,
			sf::Color(myColor.r, myColor.g, myColor.b, myColor.a - Util::RandFloat(0, MODULATION)),
			sf::Vector2f(Util::RandFloat(2, myMaxParticleSize), Util::RandFloat(2, myMaxParticleSize)),
			Util::RandFloat(LIFESPAN_MIN, LIFESPAN_MAX),
			myUseGravity));
		mySpawnTimer = 1.f / myFrequency;
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

void ParticleFountain::ToggleGravity()
{
	myUseGravity = !myUseGravity;
}
