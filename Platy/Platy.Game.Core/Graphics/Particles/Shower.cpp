#include "Shower.h"

#include "Util/Util.h"

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

void Shower::Update(const float& deltaTime)
{
	ParticleEmitter::Update(deltaTime);
}

void Shower::ResetParticle(const size_t& i)
{
	myParticles[i].velocity = Platy::Game::Core::Util::DegToVec2(static_cast<int>(myOrientation) - myEmissionAngle);
	myParticleVertices[i * 4].position = GetShowerPosition();
	ParticleEmitter::ResetParticle(i);
}

sf::Vector2f Shower::GetShowerPosition() const
{
	switch (myOrientation)
	{
	case EOrientation::UP:
		return {Platy::Core::Util::RandFloat(myPosition.x, myPosition.x + myLength), myPosition.y};
	case EOrientation::DOWN:
		return {myPosition.x + Platy::Core::Util::RandFloat(0, myLength), myPosition.y};
	case EOrientation::RIGHT:
	case EOrientation::LEFT:
		return {myPosition.x, Platy::Core::Util::RandFloat(myPosition.y, myPosition.y + myLength)};
	}
	return {};
}
