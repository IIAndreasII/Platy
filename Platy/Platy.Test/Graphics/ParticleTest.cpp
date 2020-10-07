#include "ParticleTest.h"

#include "SFML/Graphics/Color.hpp"
#include "Graphics/Colors.h"
#include "Graphics/Factories/ParticleEmitterFactory.h"
#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Graphics/Particles/Enum.h"

using namespace Platy::Core;
using namespace Platy::Game::Graphics;

ParticleTest::ParticleTest()
	:
	myExplosionTimer(0),
	myExplosionInterval(1)

{
	ParticleEmitterFactory::CreateCloud(10, sf::Vector2f(90, 50), C_GREY_LIGHT, 3000, 5, 2.5f,
	                                    720);
	ParticleEmitterFactory::CreateShower(4, EOrientation::DOWN, sf::Vector2f(100, 50), C_RED, 3000, 200, 2, 700,
	                                     true,
	                                     90, 9.82f * 2);
	ParticleEmitterFactory::CreateFountain(4, sf::Vector2f(600, 700), C_CYAN, 1500, 200, 1.f, 270, 35);
	ParticleEmitterFactory::CreateFountain(4, sf::Vector2f(800, 700), C_CYAN, 1500, 350, 1.5f, 270, 35, false, false,
	                                       9.82f * 2);
}

void ParticleTest::Update(const float& someDeltaTime)
{
	myExplosionTimer -= someDeltaTime;
	if (myExplosionTimer <= 0)
	{
		ParticleEmitterFactory::CreateExplosion(
			4, sf::Vector2f(Util::RandFloat(600, 1200), Util::RandFloat(100, 600)),
			C_ORANGE, 1000, 300, 1);
		myExplosionTimer = myExplosionInterval;
	}
}
