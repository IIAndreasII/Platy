#include "ParticleFactory.h"
#include "Particle.h"


ParticleFactory::~ParticleFactory()
{
}

void ParticleFactory::Init()
{
}

Particle ParticleFactory::CreateParticle(sf::Vector2f* aPosition, const sf::Vector2f& aVelocity, const sf::Color& aColor, const sf::Vector2f& aSize, const float& aLifespan, const float& gravity, const bool& shouldFade)
{
	return Particle(aPosition, aVelocity, aColor, aSize, aLifespan, gravity, shouldFade);
}
