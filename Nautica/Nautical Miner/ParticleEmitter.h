#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Particle.h"

#include <vector>
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics.hpp"

constexpr float INTENSITY_MODULATION_DIVISER_EXPLOSION = 1.1f;
constexpr float INTENSITY_MODULATION_DIVISER_FOUNTAIN = 6;
constexpr float INTENSITY_MODULATION_DIVISER_SHOWER = 6;
constexpr float COLOR_MODULATION = 150;

enum class EOrientation;

enum class EParticleEmitterType
{
	FOUNTAIN,
	SHOWER,
	EXPLOSION
};

class ParticleEmitter : public sf::Drawable, public sf::Transformable
{
public:
	// Creates an explosion
	ParticleEmitter(
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const unsigned& aParticleCount, 
		const float& anIntensity,
		const float& aLifeTime,
		const float& someGravity);

	// Creates a fountain
	ParticleEmitter(
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const unsigned& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& anEmissionAngle,
		const float& aSpreadAngle,
		const float& someGravity);

	// Creates a shower
	ParticleEmitter(
		const EOrientation anOrientation,
		const sf::Vector2f& aPosition,
		const sf::Color& aColor,
		const unsigned& aParticleCount,
		const float& anIntensity,
		const float& aLifeTime,
		const float& aLength,
		const float& anEmissionAngle,
		const float& someGravity);
	
	~ParticleEmitter();

	void Update(const float& deltaTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	inline void SetPosition(const sf::Vector2f& aPosition);

	const bool GetActive() const;

private:
	
	struct Particle
	{
		sf::Vector2f velocity;
		float lifeTime;
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

	EOrientation myOrientation;
	const EParticleEmitterType myType;
	sf::Vector2f myPosition;
	sf::Color myColor;
	std::vector<Particle> myParticles;
	sf::VertexArray myParticleVertices;

	const sf::Vector2f GetShowerPosition() const;
};

#endif