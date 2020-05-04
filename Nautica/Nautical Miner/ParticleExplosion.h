#ifndef PARTICLEEXPLOSION_H
#define PARTICLEEXPLOSION_H

#include "ParticleEmitter.h"

constexpr float INTENSITY_MODULATION = 75;
constexpr float DEFAULT_EXPLOSION_LIFESPAN = 1;

class Particle;

class ParticleExplosion : public ParticleEmitter
{
public:
	ParticleExplosion(
		sf::Vector2f* aPosition, 
		const sf::Color& aColor, 
		const unsigned& nbrOfParticles, 
		const float& aParticleMaxSize, 
		const float& anIntensity, 
		const float& gravity, 
		const float& aLifeSpan,
		const bool& shouldParticlesFade);

	~ParticleExplosion();

	void Update(float& deltaTime) override;
	void Draw(sf::RenderWindow& aWindow) override;

	const bool& GetActive() const override;

private:
	
	float myLifespan;

	void MakeParticle() override;
};

#endif