#ifndef KEYBOARDEVENTHANDLER_H
#define KEYBOARDEVENTHANDLER_H

#include "SFML/Window/Event.hpp"

//
// TODO: Add message codes for each key I want in the game, i.e wasd
//

class KeyboardEventHandler
{
public:
	~KeyboardEventHandler();

	static void HandleEvent(const sf::Event& anEvent);

private:
	KeyboardEventHandler();
};

#endif