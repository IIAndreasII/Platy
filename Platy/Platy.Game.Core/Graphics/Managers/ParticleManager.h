#ifndef PARTICLE_MANAGER_H
#define PARTICLE_MANAGER_H

#define ASYNC 1

#if ASYNC
#include <future>
#endif

#include <vector>
#include "Graphics/Particles/ParticleEmitter.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			constexpr unsigned PARTICLE_COUNT_MAX = 10000;

			typedef ParticleEmitter* ParticleEmitterPtr;

			class ParticleManager final
			{
			public:
				~ParticleManager();

				static void Init();

				static void Update(const float& someDeltaTime);
				static void EarlyDraw(sf::RenderWindow& aWindow);
				static void Draw(sf::RenderWindow& aWindow);
				static void AddEmitter(ParticleEmitterPtr anEmitter, bool isEarly = false);
				static void RemoveAllEffects();

				static size_t GetParticleCount();

			private:

				static std::vector<ParticleEmitterPtr> myEarlyParticleEmitters;
				static std::vector<ParticleEmitterPtr> myParticleEmitters;
#if ASYNC
				static std::vector<std::future<void>> myFutures;
#endif
			};
		}
	}
}
#endif
