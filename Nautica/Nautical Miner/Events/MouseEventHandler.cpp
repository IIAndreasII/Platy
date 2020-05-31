#include "MouseEventHandler.h"

MouseEventHandler::~MouseEventHandler()
{
}

void MouseEventHandler::HandleEvent(const sf::Event& anEvent)
{
	// TODO: Add suitable events
	switch (anEvent.type)
	{
	case sf::Event::MouseButtonPressed:

		switch (anEvent.key.code)
		{
		case sf::Mouse::Left:
			break;
		case sf::Mouse::Right:
			break;
		}

		break;
	case sf::Event::MouseButtonReleased:
		
		switch (anEvent.key.code)
		{
		case sf::Mouse::Left:
			break;
		case sf::Mouse::Right:
			break;
		}
		
		break;
	}
}
