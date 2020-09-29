#include "ParticleEmitterFactory.h"

#include "Graphics/Particles/Cloud.h"
#include "Graphics/Particles/Enum.h"
#include "Graphics/Particles/Explosion.h"
#include "Graphics/Particles/Fountain.h"
#include "Graphics/Particles/ParticleEmitter.h"
#include "Graphics/Particles/Shower.h"
#include "Managers/ParticleManager.h"


ParticleEmitter* ParticleEmitterFactory::CreateFountainPtr(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                                           const sf::Color aColor, const unsigned aNbrOfParticles,
                                                           const float anIntensity, const float aLifeTime,
                                                           const float anEmissionAngle, const float aSpreadAngle,
                                                           const bool isShortLived, const bool early,
                                                           const float someGravity, const bool shouldFade)
{
	ParticleEmitter* ptr = new Fountain(aParticleMaxSize, aPosition, aColor, aNbrOfParticles, anIntensity, aLifeTime,
	                                    anEmissionAngle, aSpreadAngle, someGravity, isShortLived, shouldFade);
	ParticleManager::AddEmitter(ptr, early);
	return ptr;
}

void ParticleEmitterFactory::CreateFountain(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                            const sf::Color aColor,
                                            const unsigned aNbrOfParticles, const float anIntensity,
                                            const float aLifeTime,
                                            const float anEmissionAngle, const float aSpreadAngle,
                                            const bool isShortLived, const bool early,
                                            const float someGravity, const bool shouldFade)
{
	ParticleManager::AddEmitter(new Fountain(aParticleMaxSize, aPosition, aColor, aNbrOfParticles, anIntensity,
	                                         aLifeTime,
	                                         anEmissionAngle, aSpreadAngle, someGravity, isShortLived, shouldFade),
	                            early);
}

ParticleEmitter* ParticleEmitterFactory::CreateExplosionPtr(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                                            const sf::Color aColor, const unsigned nbrOfParticles,
                                                            const float anIntensity, const float aLifeTime,
                                                            const bool early, const float someGravity,
                                                            const bool shouldFade)
{
	ParticleEmitter* ptr = new Explosion(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anIntensity, aLifeTime,
	                                     someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr, early);
	return ptr;
}

void ParticleEmitterFactory::CreateExplosion(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                             const sf::Color aColor, const unsigned nbrOfParticles,
                                             const float anIntensity,
                                             const float aLifeTime, const bool early, const float someGravity,
                                             const bool shouldFade)
{
	ParticleManager::AddEmitter(new Explosion(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anIntensity,
	                                          aLifeTime,
	                                          someGravity, shouldFade), early);
}

ParticleEmitter* ParticleEmitterFactory::CreateCloudPtr(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                                        const sf::Color aColor, const unsigned nbrOfParticles,
                                                        const float anIntensity, const float aLifeTime,
                                                        const float aLength, const bool early, const float someGravity,
                                                        const bool shouldFade)
{
	ParticleEmitter* ptr = new Cloud(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anIntensity, aLifeTime,
	                                 aLength, someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr, early);
	return ptr;
}

void ParticleEmitterFactory::CreateCloud(const float aParticleMaxSize, const sf::Vector2f aPosition,
                                         const sf::Color aColor,
                                         const unsigned nbrOfParticles, const float anIntensity, const float aLifeTime,
                                         const float aLength,
                                         const bool early, const float someGravity,
                                         const bool shouldFade)
{
	ParticleManager::AddEmitter(new Cloud(aParticleMaxSize, aPosition, aColor, nbrOfParticles, anIntensity, aLifeTime,
	                                      aLength, someGravity, shouldFade), early);
}

ParticleEmitter* ParticleEmitterFactory::CreateShowerPtr(const float aParticleMaxSize, const EOrientation anOrientation,
                                                         const sf::Vector2f aPosition, const sf::Color aColor,
                                                         const unsigned nbrOfParticles, const float anIntensity,
                                                         const float aLifeTime, const float aLength, const bool early,
                                                         const float anEmissionAngle, const float someGravity,
                                                         const bool shouldFade)
{
	ParticleEmitter* ptr = new Shower(aParticleMaxSize, anOrientation, aPosition, aColor, nbrOfParticles, anIntensity,
	                                  aLifeTime, aLength, anEmissionAngle, someGravity, shouldFade);
	ParticleManager::AddEmitter(ptr, early);
	return ptr;
}

void ParticleEmitterFactory::CreateShower(const float aParticleMaxSize, const EOrientation anOrientation,
                                          const sf::Vector2f aPosition,
                                          const sf::Color aColor, const unsigned nbrOfParticles,
                                          const float anIntensity, const float aLifeTime,
                                          const float aLength, const bool early,
                                          const float anEmissionAngle, const float someGravity, const bool shouldFade)
{
	ParticleManager::AddEmitter(new Shower(aParticleMaxSize, anOrientation, aPosition, aColor, nbrOfParticles,
	                                       anIntensity,
	                                       aLifeTime, aLength, anEmissionAngle, someGravity, shouldFade), early);
}
