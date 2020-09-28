#ifndef PARTICLE_EMITTER_FACTORY_H
#define PARTICLE_EMITTER_FACTORY_H

#include "Graphics/Colors.h"
#include "SFML/System/Vector2.hpp"

class ParticleEmitter;
enum class EOrientation;
class ParticleFountain;
class ParticleExplosion;

class ParticleEmitterFactory
{
public:
	~ParticleEmitterFactory() = default;

	static ParticleEmitter* CreateFountain(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned aNbrOfParticles,
		float anIntensity,
		float aLifeTime,
		float anEmissionAngle,
		float aSpreadAngle,
		bool isShortLived,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static ParticleEmitter* CreateExplosion(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned nbrOfParticles,
		float anIntensity,
		float aLifeTime,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static ParticleEmitter* CreateCloud(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned nbrOfParticles,
		float anIntensity,
		float aLifeTime,
		float aLength,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static ParticleEmitter* CreateShower(
		float aParticleMaxSize,
		EOrientation anOrientation,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned nbrOfParticles,
		float anIntensity,
		float aLifeTime,
		float aLength,
		bool early = false,
		float anEmissionAngle = 90,
		float someGravity = 0,
		bool shouldFade = true);
};

#endif
