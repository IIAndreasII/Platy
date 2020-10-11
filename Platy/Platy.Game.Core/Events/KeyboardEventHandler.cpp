#include "KeyboardEventHandler.h"

#include <SFML/Window/Event.hpp>

#include "Postmaster/PostMaster.h"
#include "Postmaster/MessageType.h"


namespace Platy
{
	namespace Game
	{
		void KeyboardEventHandler::HandleEvent(const sf::Event& anEvent)
		{
			switch (anEvent.type)
			{
			case sf::Event::KeyPressed:
				switch (anEvent.key.code)
				{
				case sf::Keyboard::Key::Escape:

					break;

				case sf::Keyboard::Key::A:
					PostMaster::SendMessage(EMessageType::KEY_A_PRESSED);
					break;
				case sf::Keyboard::Key::D:
					PostMaster::SendMessage(EMessageType::KEY_D_PRESSED);
					break;

				default:
					break;
				}
				break;

			case sf::Event::KeyReleased:
				switch (anEvent.key.code)
				{
				case sf::Keyboard::Key::A:
					PostMaster::SendMessage(EMessageType::KEY_A_RELEASED);
					break;
				case sf::Keyboard::Key::D:
					PostMaster::SendMessage(EMessageType::KEY_D_RELEASED);
					break;
				case sf::Keyboard::Key::Escape:
					PostMaster::SendMessage(EMessageType::KEY_ESCAPE_RELEASED);
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
}
