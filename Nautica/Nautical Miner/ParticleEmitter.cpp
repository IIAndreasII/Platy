#include "pch.h"
#include "ParticleEmitter.h"
#include "Particle.h"

ParticleEmitter::~ParticleEmitter()
{
	//myParticles.clear();
}

void ParticleEmitter::Update(float& deltaTime)
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		myParticles.at(i).Update(deltaTime);
	}
}

void ParticleEmitter::Draw(sf::RenderWindow& aWindow)
{
	for (Particle it : myParticles)
	{
		it.Draw(aWindow);
	}
}

void ParticleEmitter::Deactivate()
{
	myIsActive = false;
}

const bool& ParticleEmitter::GetActive() const
{
	return myIsActive;
}
