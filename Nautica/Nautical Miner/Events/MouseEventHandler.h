#ifndef MOUSEEVENTHANDLER_H
#define MOUSEEVENTHANDLER_H

#include "SFML/Window/Event.hpp"

//
// TODO: Add message codes for mouse events
//

class MouseEventHandler
{
public:
	~MouseEventHandler();

	static void HandleEvent(const sf::Event& anEvent);

private:
	MouseEventHandler();
};

#endif