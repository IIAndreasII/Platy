#include "ParticleEmitter.h"
#include "Particle.h"

void ParticleEmitter::Update(float& deltaTime)
{
	for (int i = myParticles.size() - 1; i >= 0; i--)
	{
		myParticles.at(i).Update(deltaTime);
		if (!myParticles.at(i).GetAlive())
		{
			myParticles.erase(myParticles.begin() + i);
		}
	}
}

void ParticleEmitter::Draw(sf::RenderWindow& aWindow)
{
	for (Particle it : myParticles)
	{
		it.Draw(aWindow);
	}
}
