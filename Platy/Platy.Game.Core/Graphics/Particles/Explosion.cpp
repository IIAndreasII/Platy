#include "Explosion.h"

#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Util/Util.h"
#include "Util/Util.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			Explosion::Explosion(
				const float& aParticleMaxSize,
				const sf::Vector2f& aPosition,
				const sf::Color& aColor,
				const size_t& aParticleCount,
				const float& anIntensity,
				const float& aLifeTime,
				const float& someGravity,
				const bool& shouldFade)
				: ParticleEmitter(
					aParticleMaxSize,
					EOrientation(),
					aPosition,
					aColor,
					aParticleCount,
					anIntensity,
					aLifeTime,
					0,
					0,
					someGravity,
					INTENSITY_MODULATION_DIVIDER_EXPLOSION,
					shouldFade,
					true)
			{
				for (size_t i = 0; i < myParticles.size(); i++)
				{
					ResetParticle(i);
				}
			}

			Explosion::~Explosion() = default;

			void Explosion::Update(const float& someDeltaTime)
			{
				myLifeTime -= someDeltaTime;
				if (myLifeTime <= 0)
				{
					return;
				}
				ParticleEmitter::Update(someDeltaTime);
			}

			void Explosion::ResetParticle(const size_t& anIndex)
			{
				myParticles[anIndex].velocity = Util::DegToVec2(Core::Util::RandFloat(0, 360));
				myParticleVertices[anIndex * 4].position = myPosition;
				ParticleEmitter::ResetParticle(anIndex);
			}
		}
	}
}
