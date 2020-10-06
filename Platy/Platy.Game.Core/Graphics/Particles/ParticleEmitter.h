#ifndef PARTICLE_EMITTER_H
#define PARTICLE_EMITTER_H

#include "Enum.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include <vector>

constexpr float INTENSITY_MODULATION_DIVIDER_EXPLOSION = 1.1f;
constexpr float INTENSITY_MODULATION_DIVIDER_FOUNTAIN = 6;
constexpr float INTENSITY_MODULATION_DIVIDER_SHOWER = 6;
constexpr float COLOR_MODULATION = 150;

class ParticleEmitter : public sf::Drawable
{
protected:

	ParticleEmitter(
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
		const float& aModulationDivider,
		const bool& shouldFade,
		const bool& isShortLived);

public:
	~ParticleEmitter() override;

	virtual void Update(const float& deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void SetPosition(float x, float y);
	void SetPosition(const sf::Vector2f& aPosition);
	void Destroy();

	bool GetActive() const;
	size_t GetParticleCount() const;

protected:

	struct Particle
	{
		Particle() : lifeTime(), alpha()
		{
		}

		~Particle() = default;
		sf::Vector2f velocity;
		float lifeTime;
		short alpha;
	};

	virtual void ResetParticle(const size_t& i);

	float myLifeTime;
	float myEmissionAngle;
	float myLength;

	bool myIsShortLived;

	EOrientation myOrientation;
	sf::Vector2f myPosition;
	std::vector<Particle> myParticles;
	sf::VertexArray myParticleVertices;

private:
	float myGravity;
	float myInitLifeTime;
	float myIntensity;
	float myIntensityDivider;
	float myParticleSize;

	bool myShouldFade;

	sf::Color myColor;
};

#endif
