#ifndef KEYBOARD_EVENT_HANDLER_H
#define KEYBOARD_EVENT_HANDLER_H

#include "SFML/Window/Event.hpp"

//
// TODO: Add message codes for each key I want in the game, i.e w,a,s d
//

class KeyboardEventHandler
{
public:
	~KeyboardEventHandler() = default;

	static void HandleEvent(const sf::Event& anEvent);
};

#endif
