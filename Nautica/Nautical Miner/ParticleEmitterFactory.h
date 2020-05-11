#ifndef PARTICLEEMITTERFACTORY_H
#define PARTICLEEMITTERFACTORY_H

//#include "Util.h"
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
		const sf::Vector2f aPosition, 
		const sf::Color aColor,
		const unsigned aNbrOfParticles,
		const float anIntensity,  
		const float aLifeTime,
		const float anEmissionAngle, 
		const float aSpreadAngle, 
		const float gravity = 0);
	
	static void CreateExplosion(
		const sf::Vector2f aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float anInensity,
		const float aLifeSpan,
		const float gravity = 0);

	static void CreateShower(
		const EOrientation anOrientation,
		const sf::Vector2f aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float anIntensity,
		const float aLifeSpan,
		const float aLength,
		const float anEmissionAngle = 90,
		const float gravity = 0);

private:
	ParticleEmitterFactory();

};

#endif