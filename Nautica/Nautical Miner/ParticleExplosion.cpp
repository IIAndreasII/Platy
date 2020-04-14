#include "ParticleExplosion.h"

ParticleExplosion::ParticleExplosion(const sf::Vector2f aPosition, const unsigned nbrOfParticles, const float anIntensity, const bool useGravity, const float lifeSpan)
{
	for (size_t i = 0; i < nbrOfParticles; i++)
	{

	}
}

ParticleExplosion::~ParticleExplosion()
{
}

void ParticleExplosion::Update(float& deltaTime)
{
	ParticleEmitter::Update(deltaTime);
}

void ParticleExplosion::Draw(sf::RenderWindow& aWindow)
{
	ParticleEmitter::Draw(aWindow);
}
