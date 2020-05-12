#include "pch.h"
#include "ParticleEmitter.h"
#include "Particle.h"
#include "Util.h"

////////////////////////////////////////////
//              Explosions				  //
////////////////////////////////////////////
ParticleEmitter::ParticleEmitter(
	const float& aParticleMaxSize,
	const sf::Vector2f& aPosition, 
	const sf::Color& aColor, 
	const unsigned& aParticleCount, 
	const float& anIntensity, 
	const float& aLifeTime, 
	const float& someGravity,
	const bool& shouldFade)
	:
	myPosition(aPosition),
	myType(EParticleEmitterType::EXPLOSION),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Quads, aParticleCount * 4),
	myColor(aColor),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myGravity(someGravity),
	myIntensity(anIntensity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_EXPLOSION),
	myEmissionAngle(),
	mySpreadAngle(),
	myLength(),
	myOrientation(),
	myParticleSize(aParticleMaxSize),
	myShouldFade(shouldFade)
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		ResetParticle(i);
	}
}

////////////////////////////////////////////
//                 Clouds  				  //
////////////////////////////////////////////
ParticleEmitter::ParticleEmitter(
	const float& aParticleMaxSize,
	const sf::Vector2f& aPosition,
	const sf::Color& aColor,
	const unsigned& aParticleCount,
	const float& anIntensity,
	const float& aLifeTime,
	const float& aLength,
	const float& someGravity,
	const bool& shouldFade)
	:
	myPosition(aPosition),
	myType(EParticleEmitterType::CLOUD),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Quads, aParticleCount * 4),
	myColor(aColor),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myGravity(someGravity),
	myIntensity(anIntensity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_EXPLOSION),
	myEmissionAngle(),
	mySpreadAngle(),
	myLength(aLength),
	myOrientation(),
	myParticleSize(aParticleMaxSize),
	myShouldFade(shouldFade)
{
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		ResetParticle(i);
	}
}

////////////////////////////////////////////
//              Fountains				  //
////////////////////////////////////////////
ParticleEmitter::ParticleEmitter(
	const float& aParticleMaxSize,
	const sf::Vector2f& aPosition,
	const sf::Color& aColor,
	const unsigned& aParticleCount,
	const float& anIntensity,
	const float& aLifeTime,
	const float& anEmissionAngle, 
	const float& aSpreadAngle, 
	const float& someGravity,
	const EParticleEmitterType& aType,
	const bool& shouldFade)
	:
	myType(aType),
	myPosition(aPosition),
	myColor(aColor),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Quads, aParticleCount * 4),
	myIntensity(anIntensity),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myEmissionAngle(anEmissionAngle),
	mySpreadAngle(aSpreadAngle),
	myGravity(someGravity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_FOUNTAIN),
	myLength(),
	myOrientation(),
	myParticleSize(aParticleMaxSize),
	myShouldFade(shouldFade)
{
	if (aType == EParticleEmitterType::FOUNTAIN_BURST)
	{
		for (size_t i = 0; i < myParticles.size(); i++)
		{
			ResetParticle(i);
		}
	}
}

////////////////////////////////////////////
//               Showers 				  //
////////////////////////////////////////////
ParticleEmitter::ParticleEmitter(
	const float& aParticleMaxSize,
	const EOrientation anOrientation, 
	const sf::Vector2f& aPosition, 
	const sf::Color& aColor,
	const unsigned& aParticleCount,
	const float& anIntensity,
	const float& aLifeTime,
	const float& aLength, 
	const float& anEmissionAngle, 
	const float& someGravity,
	const bool& shouldFade)
	:
	myOrientation(anOrientation),
	myType(EParticleEmitterType::SHOWER),
	myColor(aColor),
	myPosition(aPosition),
	myParticles(aParticleCount),
	myParticleVertices(sf::PrimitiveType::Quads, aParticleCount * 4),
	myIntensity(anIntensity),
	myLifeTime(aLifeTime),
	myInitLifeTime(aLifeTime),
	myLength(aLength),
	myEmissionAngle(anEmissionAngle),
	myGravity(someGravity),
	myIntensityDivider(INTENSITY_MODULATION_DIVISER_SHOWER),
	mySpreadAngle(),
	myParticleSize(aParticleMaxSize),
	myShouldFade(shouldFade)
{
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::Update(const float& deltaTime)
{
	if (myType == EParticleEmitterType::EXPLOSION || myType == EParticleEmitterType::FOUNTAIN_BURST)
	{
		myLifeTime -= deltaTime;
		if (myLifeTime <= 0)
		{
			return;
		}
	}
	for (size_t i = 0; i < myParticles.size(); i++)
	{
		Particle& p = myParticles[i];
		p.lifeTime -= deltaTime;
		if (myType != EParticleEmitterType::EXPLOSION && myType != EParticleEmitterType::FOUNTAIN_BURST)
		{
			if (p.lifeTime <= 0)
			{
				ResetParticle(i);
				continue;
			}
		}
		p.velocity.y += myGravity * myGravity * deltaTime;

		float ratio = (p.lifeTime / myInitLifeTime > 0) ? (p.lifeTime / myInitLifeTime) : 0;
		for (size_t j = 0; j < 4; j++)
		{
			myParticleVertices[i * 4 + j].position += p.velocity * deltaTime;
			myParticleVertices[i * 4 + j].color.a = myShouldFade ? ratio * p.alpha : p.alpha;
		}
	}
}

void ParticleEmitter::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;
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

const bool ParticleEmitter::GetActive() const
{
	return myLifeTime > 0;
}

const size_t& ParticleEmitter::GetParticleCount() const
{
	return myParticles.size();
}

void ParticleEmitter::ResetParticle(const size_t& i)
{
	switch (myType)
	{
	case EParticleEmitterType::CLOUD:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(0, 360));
		myParticleVertices[i * 4].position = GetShowerPosition();
		myParticleVertices[i * 4].position += sf::Vector2f(0, Util::RandFloat(-20, 20));
		break;

	case EParticleEmitterType::EXPLOSION:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(0, 360));
		myParticleVertices[i * 4].position = myPosition;
		break;

	case EParticleEmitterType::FOUNTAIN:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle));
		myParticleVertices[i * 4].position = myPosition;
		break;

	case EParticleEmitterType::SHOWER:
		myParticles[i].velocity = Util::DegToVec2(static_cast<int>(myOrientation) - myEmissionAngle);
		myParticleVertices[i * 4].position = GetShowerPosition();
		break;

	case EParticleEmitterType::FOUNTAIN_BURST:
		myParticles[i].velocity = Util::DegToVec2(Util::RandFloat(myEmissionAngle - mySpreadAngle, myEmissionAngle + mySpreadAngle));
		myParticleVertices[i * 4].position = myPosition;
		break;
	}
	myParticles[i].velocity *= (myIntensity - Util::RandFloat(0, myIntensity / myIntensityDivider));
	myParticles[i].lifeTime = (Util::RandFloat(myInitLifeTime / 2, myInitLifeTime));

	float randWidth = Util::RandFloat(2, myParticleSize);
	float randHeight = Util::RandFloat(2, myParticleSize);
	myParticleVertices[i * 4 + 1].position = myParticleVertices[i * 4].position + sf::Vector2f(0, randWidth);			 //////////////////////////////////////////////////////////
	myParticleVertices[i * 4 + 2].position = myParticleVertices[i * 4].position + sf::Vector2f(randWidth, randHeight);   // It's technically a bug, but I'm calling it a feature //
	myParticleVertices[i * 4 + 3].position = myParticleVertices[i * 4].position + sf::Vector2f(randHeight, 0);			 //////////////////////////////////////////////////////////
	myParticles[i].alpha = myColor.a - Util::RandFloat(0, 100);
	for (size_t j = 0; j < 4; j++)
	{
		myParticleVertices[i * 4 + j].color = myColor;
		myParticleVertices[i * 4 + j].color.a = myParticles[i].alpha;
	}
}

const sf::Vector2f ParticleEmitter::GetShowerPosition() const
{
	switch (myOrientation)
	{
	default:
		return sf::Vector2f(myPosition.x + Util::RandFloat(0, myLength), myPosition.y);
	case EOrientation::UP:
		return sf::Vector2f(Util::RandFloat(myPosition.x, myPosition.x + myLength), myPosition.y);
	case EOrientation::RIGHT:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	case EOrientation::LEFT:
		return sf::Vector2f(myPosition.x, Util::RandFloat(myPosition.y, myPosition.y + myLength));
	}
}
