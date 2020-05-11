#include "ParticleEmitterFactory.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"

ParticleEmitterFactory::~ParticleEmitterFactory()
{
}

void ParticleEmitterFactory::CreateFountain(const sf::Vector2f aPosition, const sf::Color aColor, const unsigned aNbrOfParticles, const float anIntensity, const float aLifeTime, const float anEmissionAngle, const float aSpreadAngle, const float someGravity)
{
	ParticleManager::AddEmitter(new ParticleEmitter(aPosition, aColor, aNbrOfParticles, anIntensity, aLifeTime, anEmissionAngle, aSpreadAngle, someGravity));
}

void ParticleEmitterFactory::CreateExplosion(const sf::Vector2f aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float anInensity, const float aLifeTime, const float someGravity)
{
	ParticleManager::AddEmitter(new ParticleEmitter(aPosition, aColor, nbrOfParticles, anInensity, aLifeTime, someGravity));
}

void ParticleEmitterFactory::CreateShower(const EOrientation anOrientation, const sf::Vector2f aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float anIntensity, const float aLifeTime, const float aLength, const float anEmissionAngle, const float someGravity)
{
	ParticleManager::AddEmitter(new ParticleEmitter(anOrientation, aPosition, aColor, nbrOfParticles, anIntensity, aLifeTime, aLength, anEmissionAngle, someGravity));
}
