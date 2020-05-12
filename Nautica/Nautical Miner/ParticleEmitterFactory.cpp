#include "ParticleEmitterFactory.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"

ParticleEmitterFactory::~ParticleEmitterFactory()
{
}

ParticleEmitter* ParticleEmitterFactory::CreateFountain(const float aParticleMaxSize, const sf::Vector2f aPosition, const sf::Color aColor, const unsigned aNbrOfParticles, const float anIntensity, const float aLifeTime, const float anEmissionAngle, const float aSpreadAngle, const float someGravity, const EParticleEmitterType aType, const bool shouldFade)
{
	ParticleEmitter* ptr = new ParticleEmitter(aParticleMaxSize, aPosition, aColor, aNbrOfParticles, anIntensity, aLifeTime, anEmissionAngle, aSpreadAngle, someGravity, aType, shouldFade);
	ParticleManager::AddEmitter(ptr);
	return ptr;
}

ParticleEmitter* ParticleEmitterFactory::CreateExplosion(const float aParticleMaxSize, const sf::Vector2f aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float anInensity, const float aLifeTime, const float someGravity, const bool shouldFade)
{
	ParticleEmitter* ptr = new ParticleEmitter(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anInensity, aLifeTime, someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr);
	return ptr;
}

ParticleEmitter* ParticleEmitterFactory::CreateCloud(const float aParticleMaxSize, const sf::Vector2f aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float anInensity, const float aLifeTime, const float aLength, const float someGravity, const bool shouldFade)
{
	ParticleEmitter* ptr = new ParticleEmitter(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anInensity, aLifeTime, aLength, someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr);
	return ptr;
}

ParticleEmitter* ParticleEmitterFactory::CreateShower(const float aParticleMaxSize, const EOrientation anOrientation, const sf::Vector2f aPosition, const sf::Color aColor, const unsigned nbrOfParticles, const float anIntensity, const float aLifeTime, const float aLength, const float anEmissionAngle, const float someGravity, const bool shouldFade)
{
	ParticleEmitter* ptr = new ParticleEmitter(aParticleMaxSize, anOrientation, aPosition, aColor, nbrOfParticles, anIntensity, aLifeTime, aLength, anEmissionAngle, someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr);
	return ptr;
}
