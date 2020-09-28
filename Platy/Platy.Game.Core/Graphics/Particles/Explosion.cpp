#include "Explosion.h"

#include "Platy.Core/Util/Util.h"
#include "Util/Util.h"

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
		false)
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		ResetParticle(i);
	}
}

Explosion::~Explosion() = default;

void Explosion::Update(const float& deltaTime)
{
	myLifeTime -= deltaTime;
	if (myLifeTime <= 0)
	{
		return;
	}
	ParticleEmitter::Update(deltaTime);
}

void Explosion::ResetParticle(const size_t& i)
{
	myParticles[i].velocity = Platy::Game::Core::Util::DegToVec2(Platy::Core::Util::RandFloat(0, 360));
	myParticleVertices[i * 4].position = myPosition;
	ParticleEmitter::ResetParticle(i);
}
