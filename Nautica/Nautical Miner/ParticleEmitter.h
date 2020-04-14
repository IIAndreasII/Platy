#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Particle.h"

#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class ParticleEmitter
{
public:
	virtual void Update(float& deltaTime);
	virtual void Draw(sf::RenderWindow& aWindow);

protected:
	std::vector<Particle> myParticles;
	sf::Vector2f* myPosition;

private:
};

#endif