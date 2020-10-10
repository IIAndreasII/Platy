#include "Shower.h"


#include "Platy.Game.Core/Util/Util.h"
#include "Util/Util.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			Shower::Shower(
				const float& aParticleMaxSize,
				const EOrientation anOrientation,
				const sf::Vector2f& aPosition,
				const sf::Color& aColor,
				const size_t& aParticleCount,
				const float& anIntensity,
				const float& aLifeTime,
				const float& aLength,
				const float& anEmissionAngle,
				const float& someGravity,
				const bool& shouldFade)
				: ParticleEmitter(
					aParticleMaxSize,
					anOrientation,
					aPosition,
					aColor,
					aParticleCount,
					anIntensity,
					aLifeTime,
					aLength,
					anEmissionAngle,
					someGravity,
					INTENSITY_MODULATION_DIVIDER_SHOWER,
					shouldFade,
					false)
			{
			}

			Shower::~Shower() = default;

			void Shower::Update(const float& someDeltaTime)
			{
				ParticleEmitter::Update(someDeltaTime);
			}

			void Shower::ResetParticle(const size_t& anIndex)
			{
				myParticles[anIndex].velocity = Util::DegToVec2(
					static_cast<int>(myOrientation) - myEmissionAngle);
				myParticleVertices[anIndex * 4].position = GetShowerPosition();
				ParticleEmitter::ResetParticle(anIndex);
			}

			sf::Vector2f Shower::GetShowerPosition() const
			{
				switch (myOrientation)
				{
				case EOrientation::UP:
					return {Core::Util::RandFloat(myPosition.x, myPosition.x + myLength), myPosition.y};
				case EOrientation::DOWN:
					return {myPosition.x + Core::Util::RandFloat(0, myLength), myPosition.y};
				case EOrientation::RIGHT:
				case EOrientation::LEFT:
					return {myPosition.x, Core::Util::RandFloat(myPosition.y, myPosition.y + myLength)};
				}
				return {};
			}
		}
	}
}
