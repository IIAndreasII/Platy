#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "ParticleEmitter.h"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			class Explosion final : public ParticleEmitter
			{
			public:
				Explosion(
					const float& aParticleMaxSize,
					const sf::Vector2f& aPosition,
					const sf::Color& aColor,
					const size_t& aParticleCount,
					const float& anIntensity,
					const float& aLifeTime,
					const float& someGravity,
					const bool& shouldFade);

				~Explosion() override;

				void Update(const float& someDeltaTime) override;

			protected:

				void ResetParticle(const size_t& anIndex) override;
			};
		}
	}
}
#endif
