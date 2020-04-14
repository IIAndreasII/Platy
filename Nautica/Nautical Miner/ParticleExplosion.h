#ifndef PARTICLEEXPLOSION_H
#define PARTICLEEXPLOSION_H

#include "ParticleEmitter.h"

class Particle;

class ParticleExplosion : public ParticleEmitter
{
public:
	ParticleExplosion(const sf::Vector2f aPosition, const unsigned nbrOfParticles, const float anIntensity, const bool useGravity, const float lifeSpan);
	~ParticleExplosion();

	void Update(float& deltaTime) override;
	void Draw(sf::RenderWindow& aWindow) override;

private:
	


};

#endif