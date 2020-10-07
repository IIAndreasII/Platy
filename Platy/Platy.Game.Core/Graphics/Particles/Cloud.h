#ifndef CLOUD_H
#define CLOUD_H

#include "ParticleEmitter.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			class Cloud final : public ParticleEmitter
			{
			public:
				Cloud(
					const float& aParticleMaxSize,
					const sf::Vector2f& aPosition,
					const sf::Color& aColor,
					const size_t& aParticleCount,
					const float& anIntensity,
					const float& aLifeTime,
					const float& aLength,
					const float& someGravity,
					const bool& shouldFade);

				~Cloud() override;

				void Update(const float& someDeltaTime) override;
			protected:
				void ResetParticle(const size_t& anIndex) override;

			private:
				sf::Vector2f GetCloudPosition() const;
			};
		}
	}
}
#endif
