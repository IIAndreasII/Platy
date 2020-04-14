#ifndef PARTICLEFOUNTAIN_H
#define PARTICLEFOUNTAIN_H

#include "ParticleEmitter.h"
#include "SFML/Graphics/Color.hpp"



class ParticleFountain : public ParticleEmitter
{
public:
	ParticleFountain(sf::Vector2f* aPosition, 
					const sf::Color aColor,
					const float anEmissionAngle,
					const float aSpreadAngle,
					const float anIntensity, 
					const float aFrequency, 
					const int aMaxParticleSize,
					const bool useGravity = true);
	~ParticleFountain();

	void Update(float& deltaTime) override;
	void Draw(sf::RenderWindow& aWindow) override;

	void SetPosition(sf::Vector2f* aPosition);

	void ToggleGravity();

private:

	bool myUseGravity;

	float myEmissionAngle;
	float mySpreadAngle;
	float myFrequency;
	float myIntensity;
	float mySpawnTimer;

	unsigned myMaxParticleSize;

	sf::Color myColor;
};

#endif