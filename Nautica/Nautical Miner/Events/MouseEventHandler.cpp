#include "..\pch.h"
#include "MouseEventHandler.h"

#include "..\Postmaster\PostMaster.h"
#include "..\Postmaster\Message.h"



MouseEventHandler::~MouseEventHandler()
{
}

void MouseEventHandler::HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow)
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
			PostMaster::SendMessage(Message(sf::Mouse::getPosition(aWindow)), EMessageType::MOUSE_ON_CLICK_LEFT);
			break;
		case sf::Mouse::Right:
			break;
		}
		break;

	case sf::Event::MouseMoved:
		PostMaster::SendMessage(Message(sf::Mouse::getPosition(aWindow)), EMessageType::MOUSE_MOVED);
		break;
	}
}
