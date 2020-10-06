#include "Fountain.h"

#include "Util/Util.h"

Fountain::Fountain(
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
		  anEmissionAngle,
		  someGravity,
		  INTENSITY_MODULATION_DIVIDER_FOUNTAIN,
		  shouldFade,
		  isShortLived),
	  mySpreadAngle(aSpreadAngle)
{
	if (isShortLived)
	{
		for (size_t i = 0; i < myParticles.size(); i++)
		{
			ParticleEmitter::ResetParticle(i);
		}
	}
}

void Fountain::Update(const float& deltaTime)
{
	ParticleEmitter::Update(deltaTime);
}

void Fountain::ResetParticle(const size_t& i)
{
	myParticles[i].velocity = Platy::Game::Core::Util::DegToVec2(
		Platy::Core::Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle));
	myParticleVertices[i * 4].position = myPosition;
	ParticleEmitter::ResetParticle(i);
}
