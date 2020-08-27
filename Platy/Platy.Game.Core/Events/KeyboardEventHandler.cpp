#include "KeyboardEventHandler.h"
#include "Postmaster\PostMaster.h"
#include "Postmaster\Message.h"

KeyboardEventHandler::~KeyboardEventHandler()
{
}

void KeyboardEventHandler::HandleEvent(const sf::Event& anEvent)
{
	switch (anEvent.type)
	{
	case sf::Event::KeyPressed:
		switch (anEvent.key.code)
		{
		case sf::Keyboard::Key::Escape:
			// TODO: Toggle pause game or go up a level in menus
			break;

		case sf::Keyboard::Key::A:
			PostMaster::SendMessage(Message::Type::KEY_A_PRESSED);
			break;
		case sf::Keyboard::Key::D:
			PostMaster::SendMessage(Message::Type::KEY_D_PRESSED);
			break;

		default:
			break;
		}
		break;

	case sf::Event::KeyReleased:
		switch (anEvent.key.code)
		{
		case sf::Keyboard::Key::A:
			PostMaster::SendMessage(Message::Type::KEY_A_RELEASED);
			break;
		case sf::Keyboard::Key::D:
			PostMaster::SendMessage(Message::Type::KEY_D_RELEASED);
			break;
		case sf::Keyboard::Key::Escape:
			PostMaster::SendMessage(Message::Type::KEY_ESCAPE_RELEASED);
			break;
		default:
			break;
		}
		break;
	}
}
