#ifndef PARTICLESHOWER_H
#define PARTICLESHOWER_H

#include "ParticleEmitter.h"


class ParticleShower : public ParticleEmitter
{
public:
	ParticleShower(
		const EOrientation anOrientation,
		sf::Vector2f aPosition,
		const sf::Color aColor,
		const float aLength,
		const float anIntensity,
		const float aFrequency,
		const float aLifeSpan,
		const int aMaxParticleSize,
		const float gravity,
		const float anEmissionAngle);

	~ParticleShower();

	void Update(float& deltaTime) override;
	void Draw(sf::RenderWindow& aWindow);

private:

	float myLength;
	float myFrequency;
	float myIntensity;
	float mySpawnTimer;
	float myEmissionAngle;
	float myParticleLifeSpan;

	unsigned myMaxParticleSize;

	sf::Color myColor;
	sf::Vector2f myPosition;

	EOrientation myOrientation;

	void MakeParticle() override;
	const sf::Vector2f GetPosition();
	const sf::Vector2f GetVelocity();
};

#endif