#ifndef MOUSEEVENTHANDLER_H
#define MOUSEEVENTHANDLER_H

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
//
// TODO: Add message codes for mouse events
//

class MouseEventHandler
{
public:
	~MouseEventHandler();

	static void HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow);

private:
	MouseEventHandler();
};

#endif