#include "GamePadEventHandler.h"


#include "Postmaster/PostMaster.h"
#include "Postmaster/MessageType.h"

#include "GamePadDefinitions.h"
#include <SFML/Window/Event.hpp>


namespace Platy
{
	namespace Game
	{
		bool GamePadEventHandler::myWasLeftDPad;
		bool GamePadEventHandler::myWasUpDPad;

		void GamePadEventHandler::HandleEvent(const sf::Event& anEvent)
		{
			switch (anEvent.type)
			{
			case sf::Event::JoystickButtonPressed:
				HandleButtonPressed(anEvent);
				break;
			case sf::Event::JoystickButtonReleased:
				HandleButtonReleased(anEvent);
				break;
			case sf::Event::JoystickMoved:
				HandleJoystickMoved(anEvent);
				break;
			case sf::Event::JoystickConnected:
				HandleConnected(anEvent);
				break;
			case sf::Event::JoystickDisconnected:
				HandleDisconnected(anEvent);
				break;
			default:
				break;
			}
		}

		void GamePadEventHandler::HandleButtonPressed(const sf::Event& anEvent)
		{
			switch (anEvent.joystickButton.button)
			{
			case GAME_PAD_A:
				PostMaster::SendMessage(EMessageType::GAME_PAD_A_PRESSED);
				break;
			case GAME_PAD_B:
				PostMaster::SendMessage(EMessageType::GAME_PAD_B_PRESSED);
				break;
			case GAME_PAD_X:
				PostMaster::SendMessage(EMessageType::GAME_PAD_X_PRESSED);
				break;
			case GAME_PAD_Y:
				PostMaster::SendMessage(EMessageType::GAME_PAD_Y_PRESSED);
				break;
			case GAME_PAD_LB:
				PostMaster::SendMessage(EMessageType::GAME_PAD_LB_PRESSED);
				break;
			case GAME_PAD_RB:
				PostMaster::SendMessage(EMessageType::GAME_PAD_RB_PRESSED);
				break;
			case GAME_PAD_LS:
				PostMaster::SendMessage(EMessageType::GAME_PAD_LS_PRESSED);
				break;
			case GAME_PAD_RS:
				PostMaster::SendMessage(EMessageType::GAME_PAD_RS_PRESSED);
				break;
			default:

				break;
			}
		}

		void GamePadEventHandler::HandleButtonReleased(const sf::Event& anEvent)
		{
			switch (anEvent.joystickButton.button)
			{
			case GAME_PAD_A:
				PostMaster::SendMessage(EMessageType::GAME_PAD_A_RELEASED);
				break;
			case GAME_PAD_B:
				PostMaster::SendMessage(EMessageType::GAME_PAD_B_RELEASED);
				break;
			case GAME_PAD_X:
				PostMaster::SendMessage(EMessageType::GAME_PAD_X_RELEASED);
				break;
			case GAME_PAD_Y:
				PostMaster::SendMessage(EMessageType::GAME_PAD_Y_RELEASED);
				break;
			case GAME_PAD_LB:
				PostMaster::SendMessage(EMessageType::GAME_PAD_LB_RELEASED);
				break;
			case GAME_PAD_RB:
				PostMaster::SendMessage(EMessageType::GAME_PAD_RB_RELEASED);
				break;
			case GAME_PAD_LS:
				PostMaster::SendMessage(EMessageType::GAME_PAD_LS_RELEASED);
				break;
			case GAME_PAD_RS:
				PostMaster::SendMessage(EMessageType::GAME_PAD_RS_RELEASED);
				break;
			default:

				break;
			}
		}

		void GamePadEventHandler::HandleJoystickMoved(const sf::Event& anEvent)
		{
			// TODO: Add axis stuff for Xbox controller
			switch (anEvent.joystickMove.axis)
			{
			case sf::Joystick::X: // Left stick left/right
				// TODO: Change dead zone to adjustable constant or something
				if (anEvent.joystickMove.position >= 25 || anEvent.joystickMove.position <= -25)
				{
					// TODO: Send axis value divided by 100
				}
				else
				{
					// TODO: Send 0
				}
				break;
			case sf::Joystick::Y: // Left stick up/down
				// TODO: Change dead zone to adjustable constant or something
				if (anEvent.joystickMove.position >= 25 || anEvent.joystickMove.position <= -25)
				{
					// TODO: Send axis value divided by 100
				}
				else
				{
					// TODO: Send 0
				}
				break;
			case sf::Joystick::Z: // Triggers

				// < 0 = RT
				// > 0 = LT
				if (anEvent.joystickMove.position < 0) // RT
				{
					// TODO: Send axis value divided by 100
				}
				else if (anEvent.joystickMove.position < 0) // LT
				{
					// TODO: Send axis value divided by 100
				}
				else
				{
					// TODO: Send 0 to both LT and RT listeners
				}

				break;
			case sf::Joystick::R:
				break;
			case sf::Joystick::U: // Right stick left/right

				// TODO: Change dead zone to adjustable constant or something
				if (anEvent.joystickMove.position >= 25 || anEvent.joystickMove.position <= -25)
				{
					// TODO: Send axis value divided by 100
				}
				else
				{
					// TODO: Send 0
				}
				break;
			case sf::Joystick::V:

				// TODO: Change dead zone to adjustable constant or something
				if (anEvent.joystickMove.position >= 25 || anEvent.joystickMove.position <= -25)
				{
					// TODO: Send axis value divided by 100
				}
				else
				{
					// TODO: Send 0
				}
				break;
			case sf::Joystick::PovX:

				if (anEvent.joystickMove.position < 0) // D-Pad Left
				{
					myWasLeftDPad = true;
					// TODO: D-pad left interaction pressed
				}
				else if (anEvent.joystickMove.position > 0) // D-Pad Right
				{
					myWasLeftDPad = false;
					// TODO: D-pad right interaction pressed
				}
				else
				{
					if (myWasLeftDPad)
					{
						// TODO: D-pad left interaction released
					}
					else
					{
						// TODO: D-pad right interaction released
					}
				}
				break;
			case sf::Joystick::PovY: // D-Pad up/down

				if (anEvent.joystickMove.position < 0) // D-Pad Down
				{
					myWasUpDPad = false;
					// TODO: D-pad down interaction pressed
				}
				else if (anEvent.joystickMove.position > 0) // D-Pad Up
				{
					myWasUpDPad = true;
					// TODO: D-pad down interaction pressed
				}
				else
				{
					if (myWasUpDPad)
					{
						// TODO: D-pad up interaction released
					}
					else
					{
						// TODO: D-pad down interaction released
					}
				}
				break;

			default:
				break;
			}
		}

		void GamePadEventHandler::HandleConnected(const sf::Event& anEvent)
		{
			// TODO: Message some input manager
		}

		void GamePadEventHandler::HandleDisconnected(const sf::Event& anEvent)
		{
			// TODO: Message some input manager
		}

		const char* GamePadEventHandler::GamePadIdToCharPtr(const unsigned& id)
		{
			switch (id)
			{
			case GAME_PAD_A:
				return "A";
			case GAME_PAD_B:
				return "B";
			case GAME_PAD_X:
				return "X";
			case GAME_PAD_Y:
				return "Y";
			case GAME_PAD_LB:
				return "LB";
			case GAME_PAD_RB:
				return "RB";
			case GAME_PAD_LS:
				return "LS";
			case GAME_PAD_RS:
				return "RS";
			default:
				return "Unknown";
			}
		}
	}
}
