#ifndef GAME_UTIL_H
#define GAME_UTIL_H

#include "Platy.Core/Util/Util.h"
#include "SFML/System/Vector2.hpp"
#include <cmath>

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

				static sf::Vector2f DegToVec2(float& anAngle)
				{
					Platy::Core::Util::ClampDeg(anAngle);
					return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
				}

				static sf::Vector2f DegToVec2(float anAngle)
				{
					Platy::Core::Util::ClampDeg(anAngle);
					return sf::Vector2f(cos(anAngle * DEGTORAD), sin(anAngle * DEGTORAD));
				}

				static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, float amount)
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

			private:
				Util();
			};
		}
	}
}
#endif