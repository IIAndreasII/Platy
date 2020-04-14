#include "ParticleFactory.h"
#include "Particle.h"

std::vector<Particle> ParticleFactory::myParticlePool;

ParticleFactory::~ParticleFactory()
{
}

void ParticleFactory::Init()
{
	for (size_t i = 0; i < PARTICLE_POOL_SIZE; i++)
	{
		myParticlePool.push_back(Particle());
	}
}

const Particle ParticleFactory::CreateParticle(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color& aColor, const sf::Vector2f dimensions, const float aLifespan, const bool useGravity)
{
	if (myParticlePool.size() < PARTICLE_POOL_SIZE / 3)
	{
		RefillPool();
	}
	// TODO: make stuff work as intended
	return Particle(aPosition, aVelocity, aColor, dimensions, aLifespan, useGravity);
}

void ParticleFactory::RefillPool()
{
	while (myParticlePool.size() < PARTICLE_POOL_SIZE)
	{
		myParticlePool.push_back(Particle());
	}
}
