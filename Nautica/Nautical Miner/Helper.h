#ifndef HELPER_H
#define HELPER_H

#include "SFML/System/Vector2.hpp"

class Helper
{
public:
	~Helper();

	static sf::Vector2f Lerp(const sf::Vector2f& v1, const sf::Vector2f& v2, const float amount);


private:
	Helper();

};

#endif