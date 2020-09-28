#ifndef FOUNTAIN_H
#define FOUNTAIN_H

#include "ParticleEmitter.h"

class Fountain final : public ParticleEmitter
{
public:
	Fountain(
		const float& aParticleMaxSize,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const size_t& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& anEmissionAngle,
		const float& aSpreadAngle,
		const float& someGravity,
		const bool& isShortLived,
		const bool& shouldFade);

	void Update(const float& deltaTime) override;
protected:
	void ResetParticle(const size_t& i) override;

private:
	float mySpreadAngle;
};

#endif
