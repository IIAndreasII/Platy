#include "Cloud.h"


#include "Platy.Game.Core/Util/Util.h"
#include "Util/Util.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			Cloud::Cloud(
				const float& aParticleMaxSize,
				const sf::Vector2f& aPosition,
				const sf::Color& aColor,
				const size_t& aParticleCount,
				const float& anIntensity,
				const float& aLifeTime,
				const float& aLength,
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
					aLength,
					0,
					someGravity,
					INTENSITY_MODULATION_DIVIDER_SHOWER,
					shouldFade,
					false)
			{
				for (size_t i = 0; i < myParticles.size(); i++)
				{
					ResetParticle(i);
				}
			}

			Cloud::~Cloud() = default;

			void Cloud::Update(const float& someDeltaTime)
			{
				ParticleEmitter::Update(someDeltaTime);
			}

			void Cloud::ResetParticle(const size_t& anIndex)
			{
				myParticles[anIndex].velocity =
					Util::DegToVec2(Core::Util::RandFloat(0, 360));
				myParticleVertices[anIndex * 4].position = GetCloudPosition();
				myParticleVertices[anIndex * 4].position += sf::Vector2f(0, Core::Util::RandFloat(-20, 20));
				ParticleEmitter::ResetParticle(anIndex);
			}

			sf::Vector2f Cloud::GetCloudPosition() const
			{
				return {myPosition.x + Core::Util::RandFloat(0, myLength), myPosition.y};
			}
		}
	}
}
