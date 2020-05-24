#ifndef PARTICLEEMITTERFACTORY_H
#define PARTICLEEMITTERFACTORY_H

#include "..\Util\Colors.h"
#include "..\Util\Enum.h"
#include "SFML/System/Vector2.hpp"

class ParticleEmitter;
enum class EOrientation;
class ParticleFountain;
class ParticleExplosion;

class ParticleEmitterFactory
{
public:
	~ParticleEmitterFactory();

	static ParticleEmitter* CreateFountain(
		const float aParticleMaxSize,
		const sf::Vector2f aPosition, 
		const sf::Color aColor,
		const unsigned aNbrOfParticles,
		const float anIntensity,  
		const float aLifeTime,
		const float anEmissionAngle, 
		const float aSpreadAngle,
		const bool early = false,
		const float someGravity = 0,
		const EParticleEmitterType aType = EParticleEmitterType::FOUNTAIN,
		const bool shouldFade = true);
	
	static ParticleEmitter* CreateExplosion(
		const float aParticleMaxSize,
		const sf::Vector2f aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float anInensity,
		const float aLifeTime,
		const bool early = false,
		const float someGravity = 0,
		const bool shouldFade = true);

	static ParticleEmitter* CreateCloud(
		const float aParticleMaxSize,
		const sf::Vector2f aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float anInensity,
		const float aLifeTime,
		const float aLength,
		const bool early = false,
		const float someGravity = 0,
		const bool shouldFade = true);

	static ParticleEmitter* CreateShower(
		const float aParticleMaxSize,
		const EOrientation anOrientation,
		const sf::Vector2f aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float anIntensity,
		const float aLifeTime,
		const float aLength,
		const bool early = false,
		const float anEmissionAngle = 90,
		const float someGravity = 0,
		const bool shouldFade = true);

private:
	ParticleEmitterFactory();

};

#endif