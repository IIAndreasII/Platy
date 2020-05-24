#include "pch.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"


std::vector<ParticleEmitterPtr> ParticleManager::myParticleEmitters;
std::vector<ParticleEmitterPtr> ParticleManager::myEarlyParticleEmitters;
std::vector<std::future<void>> ParticleManager::myFutures;


ParticleManager::~ParticleManager()
{
	for (auto it : myParticleEmitters)
	{
		SafeDelete(it);
	}
	for (auto it : myEarlyParticleEmitters)
	{
		SafeDelete(it);
	}
}

void ParticleManager::Init()
{
	myParticleEmitters = std::vector<ParticleEmitterPtr>();
}

static void UpdateEmitter(ParticleEmitter* anEmitter, float deltaTime)
{
	anEmitter->Update(deltaTime);
}

#define ASYNC 1
void ParticleManager::Update(float deltaTime)
{
	for (size_t i = myParticleEmitters.size(); i > 0; i--)
	{
		if (!myParticleEmitters.at(i - 1)->GetActive())
		{
			SafeDelete(myParticleEmitters.at(i - 1));
			myParticleEmitters.erase(myParticleEmitters.begin() + i - 1);
		}
	}

	for (size_t i = myEarlyParticleEmitters.size(); i > 0; i--)
	{
		if (!myEarlyParticleEmitters.at(i - 1)->GetActive())
		{
			SafeDelete(myEarlyParticleEmitters.at(i - 1));
			myEarlyParticleEmitters.erase(myEarlyParticleEmitters.begin() + i - 1);
		}
	}
	
	for (ParticleEmitterPtr it : myEarlyParticleEmitters)
	{
#if ASYNC
		myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, deltaTime));
#else
		it->Update(deltaTime);
#endif
	}

	for (ParticleEmitterPtr it : myParticleEmitters)
	{
#if ASYNC
		myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, deltaTime));
#else
		it->Update(deltaTime);
#endif
	}
}

void ParticleManager::EarlyDraw(sf::RenderWindow& aWindow)
{
#if ASYNC
	for (size_t i = 0; i < myFutures.size(); i++)
	{
		myFutures.at(i).wait();
	}

	if (myFutures.size() > myParticleEmitters.size() * 10) // Destroy futures every n-th frame
	{
		myFutures.clear();
	}
#endif
	for (ParticleEmitterPtr it : myEarlyParticleEmitters)
	{
		aWindow.draw(*it);
	}
}

void ParticleManager::Draw(sf::RenderWindow& aWindow)
{
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
		aWindow.draw(*it);
	}
}

void ParticleManager::AddEmitter(ParticleEmitterPtr anEmitter, const bool early)
{
	if (!early)
	{
		myParticleEmitters.push_back(anEmitter);
	}
	else
	{
		myEarlyParticleEmitters.push_back(anEmitter);
	}
}

const size_t ParticleManager::GetParticleCount()
{
	size_t sum = 0;
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
		sum += it->GetParticleCount();
	}
	return sum;
}
