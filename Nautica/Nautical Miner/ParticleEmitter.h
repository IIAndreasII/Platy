#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Particle.h"

#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"

enum EOrientation
{
	HORIZONTAL,
	HORIZONTAL_INVERTED,
	VERTICAL,
	VERTICAL_INVERTED
};

constexpr float INTENSITY_MODULATION_DIVISER = 6;
constexpr float COLOR_MODULATION = 150;

class ParticleEmitter
{
public:
	virtual void Update(float& deltaTime);
	virtual void Draw(sf::RenderWindow& aWindow);

	void Deactivate();
	virtual const bool& GetActive();

protected:
	
	float myGravity;
	float myInensityModulation;

	bool myIsActive;
	
	sf::Vector2f* myPosition;
	sf::Color myColor;
	std::vector<Particle> myParticles;

	virtual void MakeParticle() = 0;

};

#endif