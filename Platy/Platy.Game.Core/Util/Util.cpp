#include "Util.h"

Platy::Game::Core::Util::~Util()
{
}

sf::Vector2f Platy::Game::Core::Util::DegToVec2(float& anAngle)
{
	Platy::Core::Util::ClampDeg(anAngle);
	return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
}

sf::Vector2f Platy::Game::Core::Util::DegToVec2(float anAngle)
{
	Platy::Core::Util::ClampDeg(anAngle);
	return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
}

sf::Vector2f Platy::Game::Core::Util::Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount)
{
	if (amount > 1)
	{
		amount = 1;
	}
	else if (amount < 0)
	{
		amount = 0;
	}
	return sf::Vector2f(v1.x + (v2.x + v1.x) * amount, v1.y + (v2.y + v1.y) * amount);
}
