#ifndef SHOWER_H
#define SHOWER_H

#include "ParticleEmitter.h"

class Shower final : public ParticleEmitter
{
public:
	Shower(
		const float& aParticleMaxSize,
		EOrientation anOrientation,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const size_t& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& aLength,
		const float& anEmissionAngle,
		const float& someGravity,
		const bool& shouldFade);

	~Shower() override;

	void Update(const float& deltaTime) override;

protected:
	void ResetParticle(const size_t& i) override;

private:

	sf::Vector2f GetShowerPosition() const;
};

#endif
