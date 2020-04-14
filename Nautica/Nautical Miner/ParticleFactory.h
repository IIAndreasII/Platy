#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H

#include <vector>

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"

constexpr unsigned PARTICLE_POOL_SIZE = 2000;

class Particle;

class ParticleFactory
{
public:
	~ParticleFactory();

	static void Init();

	static const Particle CreateParticle(const sf::Vector2f& aPosition, const sf::Vector2f& aVelocity, const sf::Color& aColor, const sf::Vector2f dimensions, const float aLifespan, const bool useGravity);

private:
	ParticleFactory();

	static void RefillPool();

	static std::vector<Particle> myParticlePool;
};

#endif