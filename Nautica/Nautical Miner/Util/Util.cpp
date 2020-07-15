#include "..\..\PlatyLog\Util\Util.h"
#include "Util.h"
#include <random>
#include <cmath>

Util::~Util()
{
}

std::string PlatyLog::Util::GetTime()
{
	return std::string();
}

int Util::RandInt(const int min, const int max)
{
	return std::rand() % min + max;
}

float Util::RandFloat(const float min, const float max)
{
	return min + static_cast<float> (rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

void Util::ClampDeg(float& anAngle)
{
	if (anAngle > 360)
	{
		anAngle -= 360;
	}
	else if (anAngle < 0)
	{
		anAngle += 360;
	}
}

template<typename T>
inline T Util::Clamp(const T min, const T max, T& value)
{
	if (value < min)
	{
		return min;
	}
	if (value > max)
	{
		return max;
	}
	return value;
}

sf::Vector2f Util::DegToVec2(float& anAngle)
{
	ClampDeg(anAngle);
	return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
}

sf::Vector2f Util::DegToVec2(float anAngle)
{
	ClampDeg(anAngle);
	return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
}

sf::Vector2f Util::Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount)
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

void Util::ToLowerCase(std::string& aString)
{
	std::transform(aString.begin(), aString.end(), aString.begin(), [](unsigned char c) {return std::tolower(c); });
}
