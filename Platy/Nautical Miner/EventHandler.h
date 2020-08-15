#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

class EventHandler
{
public:
	~EventHandler();

	static void HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow);

private:
	EventHandler();
};

#endif