#include "ParticleManager.h"
#include "Graphics/Particles/ParticleEmitter.h"
#include "Util/Util.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			std::vector<ParticleEmitterPtr> ParticleManager::myParticleEmitters;
			std::vector<ParticleEmitterPtr> ParticleManager::myEarlyParticleEmitters;
#if ASYNC
			std::vector<std::future<void>> ParticleManager::myFutures;
#endif

			using namespace Core;

			ParticleManager::~ParticleManager()
			{
				for (auto* it : myParticleEmitters)
				{
					Core::Util::SafeDelete(it);
				}
				myParticleEmitters.clear();
				for (auto* it : myEarlyParticleEmitters)
				{
					Core::Util::SafeDelete(it);
				}
				myEarlyParticleEmitters.clear();
			}

			void ParticleManager::Init()
			{
				myParticleEmitters = std::vector<ParticleEmitterPtr>();
			}

#if ASYNC
			static void UpdateEmitter(ParticleEmitter* anEmitter, const float someDeltaTime)
			{
				anEmitter->Update(someDeltaTime);
			}
#endif

			void ParticleManager::Update(const float& someDeltaTime)
			{
				for (auto i = myParticleEmitters.size(); i > 0; i--)
				{
					if (!myParticleEmitters.at(i - 1)->GetActive())
					{
						Core::Util::SafeDelete(myParticleEmitters.at(i - 1));
						myParticleEmitters.erase(myParticleEmitters.begin() + i - 1);
					}
				}

				for (auto i = myEarlyParticleEmitters.size(); i > 0; i--)
				{
					if (!myEarlyParticleEmitters.at(i - 1)->GetActive())
					{
						Core::Util::SafeDelete(myEarlyParticleEmitters.at(i - 1));
						myEarlyParticleEmitters.erase(myEarlyParticleEmitters.begin() + i - 1);
					}
				}

				for (auto* it : myEarlyParticleEmitters)
				{
#if ASYNC
					myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, someDeltaTime));
#else
		it->Update(someDeltaTime);
#endif
				}

				for (auto* it : myParticleEmitters)
				{
#if ASYNC
					myFutures.push_back(std::async(std::launch::async, UpdateEmitter, it, someDeltaTime));
#else
		it->Update(someDeltaTime);
#endif
				}
			}

			void ParticleManager::EarlyDraw(sf::RenderWindow& aWindow)
			{
#if ASYNC
				for (auto& it : myFutures)
				{
					it.wait();
				}

				if (myFutures.size() > myParticleEmitters.size() * 10) // Destroy futures every n-th frame
				{
					myFutures.clear();
				}
#endif
				for (auto* it : myEarlyParticleEmitters)
				{
					aWindow.draw(*it);
				}
			}

			void ParticleManager::Draw(sf::RenderWindow& aWindow)
			{
				for (auto* it : myParticleEmitters)
				{
					aWindow.draw(*it);
				}
			}

			void ParticleManager::AddEmitter(const ParticleEmitterPtr anEmitter, const bool isEarly)
			{
				if (!isEarly)
				{
					myParticleEmitters.push_back(anEmitter);
				}
				else
				{
					myEarlyParticleEmitters.push_back(anEmitter);
				}
			}

			void ParticleManager::RemoveAllEffects()
			{
#if ASYNC
				if (!myFutures.empty())
				{
					for (auto& it : myFutures)
					{
						it.wait();
					}
				}
				myFutures.clear();
#endif
				for (auto* it : myEarlyParticleEmitters)
				{
					Core::Util::SafeDelete(it);
				}
				myEarlyParticleEmitters.clear();
				for (auto* it : myParticleEmitters)
				{
					Core::Util::SafeDelete(it);
				}
				myParticleEmitters.clear();
			}

			size_t ParticleManager::GetParticleCount()
			{
				size_t sum = 0;
				for (auto* it : myParticleEmitters)
				{
					sum += it->GetParticleCount();
				}
				return sum;
			}
		}
	}
}
