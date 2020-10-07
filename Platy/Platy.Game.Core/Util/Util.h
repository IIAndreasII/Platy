#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include <Platy.Core/Util/Util.h>
#include <SFML/System/Vector2.hpp>

constexpr float DEG_TO_RAD = 0.0174533f;
constexpr float G = 9.82f;

namespace Platy
{
	namespace Game
	{
		class Util
		{
		public:
			Util() = delete;
			~Util() = default;

			static sf::Vector2f DegToVec2(float& anAngle);

			static sf::Vector2f DegToVec2(float anAngle);

			static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount);
		};
	}
}

#endif
