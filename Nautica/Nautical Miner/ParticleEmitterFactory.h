#ifndef PARTICLEEMITTERFACTORY_H
#define PARTICLEEMITTERFACTORY_H

#include "Util.h"
#include "Colors.h"
#include "SFML/System/Vector2.hpp"


enum class EOrientation;
class ParticleFountain;
class ParticleExplosion;

class ParticleEmitterFactory
{
public:
	~ParticleEmitterFactory();

	static void CreateFountain(
		sf::Vector2f* aPosition, 
		const sf::Color aColor, 
		const float anEmissionAngle, 
		const float aSpreadAngle, 
		const float anIntensity, 
		const float aFrequency, 
		const int aMaxParticleSize, 
		const float gravity = G,
		const bool shouldParticlesFade = false);
	
	static void CreateExplosion(
		sf::Vector2f* aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float aParticleMaxSize,
		const float anInensity,
		const float aLifeSpan,
		const float gravity = G,
		const bool shouldParticlesFade = false);

	static void CreateShower(
		const EOrientation anOrientation,
		sf::Vector2f aPosition,
		const sf::Color aColor,
		const float aLength,
		const float anIntensity,
		const float aFrequency,
		const float aLifeSpan,
		const int aMaxParticleSize,
		const float gravity = G,
		const float anEmissionAngle = 90,
		const bool shouldParticlesFade = false);

private:
	ParticleEmitterFactory();

};

#endif