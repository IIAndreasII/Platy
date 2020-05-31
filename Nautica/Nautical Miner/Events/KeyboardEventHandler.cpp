#include "..\pch.h"
#include "KeyboardEventHandler.h"

KeyboardEventHandler::~KeyboardEventHandler()
{
}

void KeyboardEventHandler::HandleEvent(const sf::Event& anEvent)
{
	switch (anEvent.type)
	{
	case sf::Event::KeyPressed:
#if DEBUG
		std::cout << "Key pressed!" << std::endl;
#endif		
		switch (anEvent.key.code)
		{
		case sf::Keyboard::Key::Escape:
			// TODO: Toggle pause game or go up a level in menus
			break;
		default:
			break;
		}
		break;
	case sf::Event::KeyReleased:
#if DEBUG
			std::cout << "Key released!" << std::endl;
#endif		
		switch (anEvent.key.code)
		{
		default:
			break;
		}
		break;
	}
}
