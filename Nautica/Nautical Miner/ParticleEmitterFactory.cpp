#include "ParticleEmitterFactory.h"
#include "ParticleManager.h"
#include "ParticleFountain.h"
#include "ParticleExplosion.h"
#include "ParticleShower.h"

ParticleEmitterFactory::~ParticleEmitterFactory()
{
}

void ParticleEmitterFactory::CreateFountain(sf::Vector2f* aPosition, const sf::Color aColor, const float anEmissionAngle, const float aSpreadAngle, const float anIntensity, const float aFrequency, const int aMaxParticleSize, const float gravity)
{
	ParticleManager::AddEmitter(new ParticleFountain(aPosition, aColor, anEmissionAngle, aSpreadAngle, anIntensity, aFrequency, aMaxParticleSize, gravity));
}

void ParticleEmitterFactory::CreateExplosion(const sf::Vector2f& aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float aParticleMaxSize, const float anInensity, const float aLifeSpan, const float gravity)
{
	ParticleManager::AddEmitter(new ParticleExplosion(aPosition, aColor, nbrOfParticles, aParticleMaxSize, anInensity, gravity, aLifeSpan));
}

void ParticleEmitterFactory::CreateShower(const EOrientation anOrientation, sf::Vector2f aPosition, const sf::Color aColor, const float aLength, const float anIntensity, const float aFrequency, const float aLifeSpan, const int aMaxParticleSize, const float gravity, const float anEmissionAngle)
{
	ParticleManager::AddEmitter(new ParticleShower(anOrientation, aPosition, aColor, aLength, anIntensity, aFrequency, aLifeSpan, aMaxParticleSize, gravity, anEmissionAngle));
}
