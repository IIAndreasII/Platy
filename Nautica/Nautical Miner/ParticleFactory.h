#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H

#include "Colors.h"
#include "SFML/System/Vector2.hpp"


constexpr unsigned PARTICLE_POOL_SIZE = 2000;

class Particle;

class ParticleFactory
{
public:
	~ParticleFactory();

	static void Init();

	static Particle CreateParticle(
		sf::Vector2f* aPosition, 
		const sf::Vector2f& aVelocity, 
		const sf::Color& aColor, 
		const sf::Vector2f& aSize, 
		const float& aLifespan, 
		const float& gravity,
		const bool& shouldFade);

private:
	ParticleFactory();

};

#endif