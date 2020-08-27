#include "MouseEventHandler.h"

#include "Postmaster\PostMaster.h"
#include "Postmaster\Message.h"


MouseEventHandler::~MouseEventHandler()
{
}

void MouseEventHandler::HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow)
{
	Message msg(sf::Mouse::getPosition(aWindow));
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
			msg.SetBool(anEvent.key.control);
			PostMaster::SendMessage(msg, Message::Type::MOUSE_ON_CLICK_LEFT);
			break;
		case sf::Mouse::Right:
			PostMaster::SendMessage(msg, Message::Type::MOUSE_ON_CLICK_RIGHT);
			break;
		}
		break;

	case sf::Event::MouseMoved:
		PostMaster::SendMessage(Message(sf::Mouse::getPosition(aWindow)), Message::Type::MOUSE_MOVED);
		break;
	}
}
