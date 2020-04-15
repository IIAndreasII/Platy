#include "pch.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"


std::vector<ParticleEmitterPtr> ParticleManager::myParticleEmitters;

ParticleManager::~ParticleManager()
{
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
		SafeDelete(it);
	}
}

void ParticleManager::Init()
{
	myParticleEmitters = std::vector<ParticleEmitterPtr>();
}

void ParticleManager::Update(float& deltaTime)
{
	for (int i = myParticleEmitters.size() - 1; i >= 0 ; i--)
	{
		myParticleEmitters.at(i)->Update(deltaTime);
		if (!myParticleEmitters.at(i)->GetActive())
		{
			myParticleEmitters.erase(myParticleEmitters.begin() + i);
		}
	}
}

void ParticleManager::Draw(sf::RenderWindow& aWindow)
{
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
		it->Draw(aWindow);
	}
}

void ParticleManager::AddEmitter(ParticleEmitterPtr anEmitter)
{
	myParticleEmitters.push_back(anEmitter);
}
