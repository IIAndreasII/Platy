#ifndef UTIL_H
#define UTIL_H

#include "SFML/System/Vector2.hpp"
#include "Enum.h"
#include <string>

constexpr float DEGTORAD = 0.0174533f;
constexpr float G = 9.82f;



class Util
{
public:
	~Util();


	// Math helpers
	template<typename T> static T Clamp(const T min, const T max, T& value);
	static int RandInt(const int min, const int max);
	static float RandFloat(const float min, const float max);

	// Geometry related
	static void ClampDeg(float& anAngle);

	// Vector related
	static sf::Vector2f DegToVec2(float& anAngle);
	static sf::Vector2f DegToVec2(float anAngle);
	static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, const float amount);

	// String util
	static void ToLowerCase(std::string& aString);

private:
	Util();
};

#endif

