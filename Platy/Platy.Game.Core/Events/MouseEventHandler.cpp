#include "MouseEventHandler.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Postmaster/PostMaster.h"
#include "Postmaster/Message.h"
#include "Postmaster/MessageType.h"

namespace Platy
{
	namespace Game
	{
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
				case sf::Mouse::Right:
					break;
				default:
					break;
				}
				break;

			case sf::Event::MouseButtonReleased:

				switch (anEvent.key.code)
				{
				case sf::Mouse::Left:
					msg.SetBool(anEvent.key.control);
					PostMaster::SendMessage(msg, EMessageType::MOUSE_ON_CLICK_LEFT);
					break;
				case sf::Mouse::Right:
					PostMaster::SendMessage(msg, EMessageType::MOUSE_ON_CLICK_RIGHT);
					break;
				default:
					break;
				}
				break;

			case sf::Event::MouseMoved:
				PostMaster::SendMessage(Message(sf::Mouse::getPosition(aWindow)), EMessageType::MOUSE_MOVED);
				break;
			default:
				break;
			}
		}
	}
}
