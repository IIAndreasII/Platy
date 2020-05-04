#ifndef PARTICLEFOUNTAIN_H
#define PARTICLEFOUNTAIN_H

#include "ParticleEmitter.h"

#include "Colors.h"


class ParticleFountain : public ParticleEmitter
{
public:
	ParticleFountain(sf::Vector2f* aPosition, 
					const sf::Color& aColor,
					const float& anEmissionAngle,
					const float& aSpreadAngle,
					const float& anIntensity, 
					const float& aFrequency,
					const int& aMaxParticleSize,
					const float& gravity,
					const bool& shouldParticlesFade);
	~ParticleFountain();

	void Update(float& deltaTime) override;
	void Draw(sf::RenderWindow& aWindow) override;
	void SetPosition(sf::Vector2f* aPosition);

private:

	float myEmissionAngle;
	float mySpreadAngle;
	float myFrequency;
	float myIntensity;
	float mySpawnTimer;

	unsigned myMaxParticleSize;

	sf::Color myColor;

	void MakeParticle() override;
};

#endif