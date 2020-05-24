#include "Helper.h"

Helper::~Helper()
{
}

sf::Vector2f Helper::Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount)
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
