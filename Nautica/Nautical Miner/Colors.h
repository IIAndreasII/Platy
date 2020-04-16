#ifndef COLORS_H
#define COLORS_H

#include "SFML/Graphics/Color.hpp"

constexpr short DARK_CONSTANT = 139;

#define C_BLUE sf::Color(0, 0, 255)
#define C_RED sf::Color(255, 0, 0)
#define C_RED_DARK sf::Color(DARK_CONSTANT, 0, 0)
#define C_GREEN sf::Color(0, 255, 0)
#define C_GREEN_DARK sf::Color(0, DARK_CONSTANT, 0)
#define C_CYAN sf::Color(0, 255, 255)
#define C_CYAN_DARK sf::Color(0, DARK_CONSTANT, DARK_CONSTANT)
#define C_WHITE sf::Color(255, 255, 255)
#define C_ORANGE sf::Color(255, 140, 0)
#define C_YELLOW sf::Color(255, 255, 0)
#define C_BROWN sf::Color(DARK_CONSTANT, 69, 19)
#define C_GREY sf::Color(128, 128, 128)
#define C_BLACK sf::Color(0, 0, 0)
#define C_PURPLE sf::Color(128, 0, 128)
#define C_RÅSA sf::Color(242, 128, 161)

#endif