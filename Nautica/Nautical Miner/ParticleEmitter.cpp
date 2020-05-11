#include "pch.h"
#include "ParticleEmitter.h"
#include "Particle.h"
#include "Util.h"

// Explosions
ParticleEmitter::ParticleEmitter(
	const sf::Vector2f& aPosition, 
	const sf::Color& aColor, 
	const unsigned& aParticleCount, 
	const float& anIntensity, 
	const float& aLifeTime, 
	const float& someGravity)
	:
	myPosition(aPosition),
	myType(EParticleEmitterType::EXPLOSION),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Points, aParticleCount),
	myColor(aColor),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myGravity(someGravity),
	myIntensity(anIntensity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_EXPLOSION),
	myEmissionAngle(),
	mySpreadAngle(),
	myLength(),
	myOrientation()
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		ResetParticle(i);
	}
}

// Fountains
ParticleEmitter::ParticleEmitter(
	const sf::Vector2f& aPosition,
	const sf::Color& aColor,
	const unsigned& aParticleCount,
	const float& anIntensity,
	const float& aLifeTime,
	const float& anEmissionAngle, 
	const float& aSpreadAngle, 
	const float& someGravity)
	:
	myType(EParticleEmitterType::FOUNTAIN),
	myPosition(aPosition),
	myColor(aColor),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Points, aParticleCount),
	myIntensity(anIntensity),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myEmissionAngle(anEmissionAngle),
	mySpreadAngle(aSpreadAngle),
	myGravity(someGravity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_FOUNTAIN),
	myLength(),
	myOrientation()
{
}

// Showers
ParticleEmitter::ParticleEmitter(
	const EOrientation anOrientation, 
	const sf::Vector2f& aPosition, 
	const sf::Color& aColor,
	const unsigned& aParticleCount,
	const float& anIntensity,
	const float& aLifeTime,
	const float& aLength, 
	const float& anEmissionAngle, 
	const float& someGravity)
	:
	myOrientation(anOrientation),
	myType(EParticleEmitterType::SHOWER),
	myColor(aColor),
	myPosition(aPosition),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Points, aParticleCount),
	myIntensity(anIntensity),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myLength(aLength),
	myEmissionAngle(anEmissionAngle),
	myGravity(someGravity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_SHOWER),
	mySpreadAngle()
{
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::Update(const float& deltaTime)
{
	if (myType == EParticleEmitterType::EXPLOSION)
	{
		myLifeTime -= deltaTime;
	}
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		Particle& p = myParticles[i];
		p.lifeTime -= deltaTime;
		if (myType != EParticleEmitterType::EXPLOSION)
		{
			if (p.lifeTime <= 0)
			{
				ResetParticle(i);
			}
		}

		p.velocity.y += myGravity * myGravity * deltaTime;
		myParticleVertices[i].position += p.velocity * deltaTime;

		float ratio = p.lifeTime / myInitLifeTime;
		myParticleVertices[i].color.a = ratio * 255 >= 0 ? ratio * 255 : 0;
	}
}


void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = NULL;
	target.draw(myParticleVertices, states);
}

inline void ParticleEmitter::SetPosition(const sf::Vector2f& aPosition)
{
	myPosition = aPosition;
}

const bool ParticleEmitter::GetActive() const
{
	return myLifeTime > 0;
}

void ParticleEmitter::ResetParticle(const size_t& i)
{
	switch (myType)
	{
	case EParticleEmitterType::EXPLOSION:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(0, 360));
		myParticleVertices[i].position = myPosition;
		break;
	case EParticleEmitterType::FOUNTAIN:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle));
		myParticleVertices[i].position = myPosition;
		break;
	case EParticleEmitterType::SHOWER:
		myParticles[i].velocity = Util::DegToVec2(static_cast<int>(myOrientation) - myEmissionAngle);
		myParticleVertices[i].position = GetShowerPosition();
		break;
	}
	myParticles[i].velocity *= (myIntensity - Util::RandFloat(0, myIntensity / myIntensityDivider));
	myParticles[i].lifeTime = (Util::RandFloat(myInitLifeTime / 2, myInitLifeTime));
	myParticleVertices[i].color = myColor;
}

const sf::Vector2f ParticleEmitter::GetShowerPosition() const
{
	switch (myOrientation)
	{
	case EOrientation::DOWN:
		return sf::Vector2f(myPosition.x + Util::RandFloat(0, myLength), myPosition.y);
	case EOrientation::UP:
		return sf::Vector2f(Util::RandFloat(myPosition.x, myPosition.x + myLength), myPosition.y);
	case EOrientation::RIGHT:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	case EOrientation::LEFT:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	default:
		return myPosition;
	}
}
