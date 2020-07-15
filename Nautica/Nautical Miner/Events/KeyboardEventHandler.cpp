#include "..\pch.h"
#include "KeyboardEventHandler.h"
#include "..\Postmaster\PostMaster.h"
#include "..\Postmaster\Message.h"

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

		case sf::Keyboard::Key::A:
			PostMaster::SendMessage(KEY_A_PRESSED);
			break;
		case sf::Keyboard::Key::D:
			PostMaster::SendMessage(KEY_D_PRESSED);
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
		case sf::Keyboard::Key::A:
			PostMaster::SendMessage(KEY_A_RELEASED);
			break;
		case sf::Keyboard::Key::D:
			PostMaster::SendMessage(KEY_D_RELEASED);
			break;

		default:
			break;
		}
		break;
	}
}
