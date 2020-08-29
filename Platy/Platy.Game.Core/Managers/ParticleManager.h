#ifndef PARTICLEMANAGER_H
#define PARTICLEMANAGER_H

#include <vector>
#include <future>
#include "SFML/Graphics/RenderWindow.hpp"
#include "../Graphics/ParticleEmitter.h"

constexpr unsigned PARTICLE_COUNT_MAX = 10000;

typedef ParticleEmitter* ParticleEmitterPtr;

class ParticleManager
{
public:
	~ParticleManager();

	static void Init();

	static void Update(float deltaTime);
	static void EarlyDraw(sf::RenderWindow& aWindow);
	static void Draw(sf::RenderWindow& aWindow);
	static void AddEmitter(ParticleEmitterPtr anEmitter, const bool early = false);
	static void RemoveAllEffects();

	static const size_t GetParticleCount();

private:
	ParticleManager();

	static std::vector<ParticleEmitterPtr> myEarlyParticleEmitters;
	static std::vector<ParticleEmitterPtr> myParticleEmitters;
	static std::vector<std::future<void>> myFutures;
};

#endif