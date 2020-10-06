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

	static ParticleEmitter* CreateFountainPtr(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned aNbrOfParticles,
		float anIntensity,
		float aLifeTime,
		float anEmissionAngle,
		float aSpreadAngle,
		bool isShortLived = false,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static void CreateFountain(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned aNbrOfParticles,
		float anIntensity,
		float aLifeTime,
		float anEmissionAngle,
		float aSpreadAngle,
		bool isShortLived = false,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static ParticleEmitter* CreateExplosionPtr(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned nbrOfParticles,
		float anIntensity,
		float aLifeTime,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static void CreateExplosion(
		float aParticleMaxSize,
		sf::Vector2f aPosition,
		sf::Color aColor,
		unsigned nbrOfParticles,
		float anIntensity,
		float aLifeTime,
		bool early = false,
		float someGravity = 0,
		bool shouldFade = true);

	static ParticleEmitter* CreateCloudPtr(
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

	static void CreateCloud(
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

	static ParticleEmitter* CreateShowerPtr(
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

	static void CreateShower(
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
