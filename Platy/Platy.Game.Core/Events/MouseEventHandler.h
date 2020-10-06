#ifndef MOUSE_EVENT_HANDLER_H
#define MOUSE_EVENT_HANDLER_H

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
//
// TODO: Add message codes for mouse events
//

class MouseEventHandler
{
public:
	~MouseEventHandler() = default;

	static void HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow);
};

#endif
