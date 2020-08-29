#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include <cmath>
#include <SFML/System/Vector2.hpp>

#include "Platy.Core/Util/Util.h"

constexpr float DEGTORAD = 0.0174533f;
constexpr float G = 9.82f;

namespace Platy
{
	namespace Game
	{
		namespace Core
		{
			class Util
			{
			public:
				~Util();

				static sf::Vector2f DegToVec2(float& anAngle);

				static sf::Vector2f DegToVec2(float anAngle);

				static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount);

			private:
				Util();
			};
		}
	}
}
#endif