#include "ParticleEmitter.h"
#include "Platy.Core/Util/Util.h"

using namespace Platy;

ParticleEmitter::ParticleEmitter(
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
	const float& aModulationDivider,
	const bool& shouldFade,
	const bool& isShortLived)
	:
	myLifeTime(aLifeTime),
	myEmissionAngle(anEmissionAngle),
	myLength(aLength),
	myIsShortLived(isShortLived),
	myOrientation(anOrientation),
	myPosition(aPosition),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Quads, aParticleCount * 4),
	myGravity(someGravity),
	myInitLifeTime(aLifeTime),
	myIntensity(anIntensity),
	myIntensityDivider(aModulationDivider),
	myParticleSize(aParticleMaxSize),
	myShouldFade(shouldFade),
	myColor(aColor)
{
}

ParticleEmitter::~ParticleEmitter() = default;

void ParticleEmitter::Update(const float& deltaTime)
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		Particle& p = myParticles.at(i);
		p.lifeTime -= deltaTime;
		if (!myIsShortLived && p.lifeTime <= 0)
		{
			ResetParticle(i);
			continue;
		}

		p.velocity.y += myGravity * myGravity * deltaTime;
		const float ratio = (p.lifeTime / myInitLifeTime > 0) ? (p.lifeTime / myInitLifeTime) : 0;
		for (size_t j = 0; j < 4; j++)
		{
			myParticleVertices[i * 4 + j].position += p.velocity * deltaTime;
			myParticleVertices[i * 4 + j].color.a = static_cast<sf::Uint8>(myShouldFade ? ratio * p.alpha : p.alpha);
		}
	}
}

void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = nullptr;
	target.draw(myParticleVertices, states);
}

void ParticleEmitter::SetPosition(const float x, const float y)
{
	myPosition.x = x;
	myPosition.y = y;
}

void ParticleEmitter::SetPosition(const sf::Vector2f& aPosition)
{
	myPosition = aPosition;
}

void ParticleEmitter::Destroy()
{
	myLifeTime = 0;
}

bool ParticleEmitter::GetActive() const
{
	return myLifeTime > 0;
}

size_t ParticleEmitter::GetParticleCount() const
{
	return myParticles.size();
}

void ParticleEmitter::ResetParticle(const size_t& i)
{
	myParticles[i].velocity *= myIntensity - Core::Util::RandFloat(0, myIntensity / myIntensityDivider);
	myParticles[i].lifeTime = Core::Util::RandFloat(myInitLifeTime / 2, myInitLifeTime);

	const float tempRandWidth = Core::Util::RandFloat(2, myParticleSize);
	const float tempRandHeight = Core::Util::RandFloat(2, myParticleSize);
	myParticleVertices[i * 4 + 1].position = myParticleVertices[i * 4].position + sf::Vector2f(0, tempRandWidth);
	myParticleVertices[i * 4 + 2].position = myParticleVertices[i * 4].position + sf::Vector2f(
		tempRandWidth, tempRandHeight);
	myParticleVertices[i * 4 + 3].position = myParticleVertices[i * 4].position + sf::Vector2f(tempRandHeight, 0);
	myParticles[i].alpha = myColor.a - static_cast<sf::Uint8>(Core::Util::RandInt(0, 100));
	for (size_t j = 0; j < 4; j++)
	{
		myParticleVertices[i * 4 + j].color = myColor;
		myParticleVertices[i * 4 + j].color.a = static_cast<sf::Uint8>(myParticles[i].alpha);
	}
}
