#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Enum.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include <vector>

constexpr float INTENSITY_MODULATION_DIVISER_EXPLOSION = 1.1f;
constexpr float INTENSITY_MODULATION_DIVISER_FOUNTAIN = 6;
constexpr float INTENSITY_MODULATION_DIVISER_SHOWER = 6;
constexpr float COLOR_MODULATION = 150;

class ParticleEmitter : public sf::Drawable
{
public:

	////////////////////////////////////////////
	//              Explosions				  //
	////////////////////////////////////////////
	ParticleEmitter(
		const float& aParticleMaxSize,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const size_t& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& someGravity,
		const bool& shouldFade);

	////////////////////////////////////////////
	//                 Clouds	  			  //
	////////////////////////////////////////////
	ParticleEmitter(
		const float& aParticleMaxSize,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const size_t& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& aLength,
		const float& someGravity,
		const bool& shouldFade);

	////////////////////////////////////////////
	//                Fountains				  //
	////////////////////////////////////////////
	ParticleEmitter(
		const float& aParticleMaxSize,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const size_t& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& anEmissionAngle,
		const float& aSpreadAngle,
		const float& someGravity,
		const EParticleEmitterType& aType,
		const bool& shouldFade);

	////////////////////////////////////////////
	//                 Showers				  //
	////////////////////////////////////////////
	ParticleEmitter(
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
		const bool& shouldFade);
	
	~ParticleEmitter();

	void Update(const float& deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void SetPosition(const float x, const float y);
	void SetPosition(const sf::Vector2f& aPosition);
	void Destroy();

	const bool GetActive() const;
	const size_t GetParticleCount() const;

private:
	
	struct Particle
	{
	public:
		Particle() : lifeTime(), alpha() {};
		~Particle() {};
		sf::Vector2f velocity;
		float lifeTime;
		short alpha;
	};

	void ResetParticle(const size_t& i);

	float myLifeTime;
	float myInitLifeTime;
	float myGravity;
	float myEmissionAngle;
	float mySpreadAngle;
	float myLength;
	float myIntensity;
	float myIntensityDivider;
	float myParticleSize;

	bool myShouldFade;

	EOrientation myOrientation;
	EParticleEmitterType myType;
	sf::Vector2f myPosition;
	sf::Color myColor;
	std::vector<Particle> myParticles;
	sf::VertexArray myParticleVertices;

	const sf::Vector2f GetShowerPosition() const;
};

#endif