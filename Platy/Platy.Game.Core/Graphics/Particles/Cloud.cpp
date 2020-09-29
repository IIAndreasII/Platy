#include "Cloud.h"

#include "Platy.Core/Util/Util.h"
#include "Util/Util.h"

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

void Cloud::Update(const float& deltaTime)
{
	ParticleEmitter::Update(deltaTime);
}

void Cloud::ResetParticle(const size_t& i)
{
	myParticles[i].velocity = Platy::Game::Core::Util::DegToVec2(Platy::Core::Util::RandFloat(0, 360));
	myParticleVertices[i * 4].position = GetCloudPosition();
	myParticleVertices[i * 4].position += sf::Vector2f(0, Platy::Core::Util::RandFloat(-20, 20));
	ParticleEmitter::ResetParticle(i);
}

sf::Vector2f Cloud::GetCloudPosition() const
{
	return {myPosition.x + Platy::Core::Util::RandFloat(0, myLength), myPosition.y};
}
