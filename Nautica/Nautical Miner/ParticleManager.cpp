#include "pch.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"
#include <mutex>


std::vector<ParticleEmitterPtr> ParticleManager::myParticleEmitters;
std::vector<std::future<void>> ParticleManager::myFutures;

static std::mutex mutex;


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

static void UpdateEmitter(ParticleEmitterPtr anEmitter, float deltaTime)
{
	std::lock_guard<std::mutex> lock(mutex);
	anEmitter->Update(deltaTime);
}


void ParticleManager::Update(float& deltaTime)
{
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
#define ASYNC 1
#if ASYNC
		myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, deltaTime));
#else
		it->Update(deltaTime);
#endif
	}
	//myFutures.at(myFutures.size() - 1).wait();
	for (size_t i = myParticleEmitters.size(); i > 0; i--)
	{
		if (!myParticleEmitters.at(i - 1)->GetActive())
		{
			myParticleEmitters.erase(myParticleEmitters.begin() + i - 1);
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
