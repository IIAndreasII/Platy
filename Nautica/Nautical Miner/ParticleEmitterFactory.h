#ifndef PARTICLEEMITTERFACTORY_H
#define PARTICLEEMITTERFACTORY_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"

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
		const float gravity);
	
	static void CreateExplosion(
		const sf::Vector2f& aPosition,
		const sf::Color aColor,
		const unsigned nbrOfParticles,
		const float aParticleMaxSize,
		const float anInensity,
		const float gravity,
		const float aLifeSpan);

	static void CreateShower(
		const EOrientation anOrientation,
		sf::Vector2f aPosition,
		const sf::Color aColor,
		const float aLength,
		const float anIntensity,
		const float aFrequency,
		const float aLifeSpan,
		const int aMaxParticleSize,
		const float gravity,
		const float anEmissionAngle = 90);

private:
	ParticleEmitterFactory();

};

#endif