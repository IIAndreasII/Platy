#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Particle.h"

#include <vector>
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


constexpr float INTENSITY_MODULATION_DIVISER = 6;
constexpr float COLOR_MODULATION = 150;

class ParticleEmitter
{
public:
	virtual ~ParticleEmitter() = 0;
	virtual void Update(float& deltaTime);
	virtual void Draw(sf::RenderWindow& aWindow);

	void Deactivate();
	virtual const bool& GetActive();

protected:
	
	float myGravity;
	float myInensityModulation;
	float myNbrOfParticles;

	bool myIsActive;
	
	sf::Vector2f* myPosition;
	sf::Color myColor;
	std::vector<Particle> myParticles;

	virtual void MakeParticle() = 0;

};

#endif