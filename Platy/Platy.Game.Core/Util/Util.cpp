#include "Util.h"

sf::Vector2f Platy::Game::Core::Util::DegToVec2(float& anAngle)
{
	Platy::Core::Util::ClampDeg(anAngle);
	return {cos(anAngle * DEG_TO_RAD), sin(anAngle * DEG_TO_RAD)};
}

sf::Vector2f Platy::Game::Core::Util::DegToVec2(float anAngle)
{
	Platy::Core::Util::ClampDeg(anAngle);
	return {cos(anAngle * DEG_TO_RAD), sin(anAngle * DEG_TO_RAD)};
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
	return {v1.x + (v2.x + v1.x) * amount, v1.y + (v2.y + v1.y) * amount};
}
