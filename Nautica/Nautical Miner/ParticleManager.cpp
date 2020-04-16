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


#define ASYNC 1
void ParticleManager::Update(float& deltaTime)
{
	for (ParticleEmitterPtr it : myParticleEmitters)
	{
#if ASYNC
		myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, deltaTime));
#else
		it->Update(deltaTime);
#endif
	}
	if (myFutures.size() != 0)
	{
		myFutures.at(myFutures.size() - 1).wait();
	}
	if (myFutures.size() > myParticleEmitters.size() * 5) // Make sure the futures are destroyed
	{
		myFutures.clear();
	}
	for (size_t i = myParticleEmitters.size(); i > 0; i--)
	{
		if (!myParticleEmitters.at(i - 1)->GetActive())
		{
			SafeDelete(myParticleEmitters.at(i - 1));
			myParticleEmitters.erase(myParticleEmitters.begin() + i - 1);
		}
	}
	//std::cout << myParticleEmitters.size() << std::endl;
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
