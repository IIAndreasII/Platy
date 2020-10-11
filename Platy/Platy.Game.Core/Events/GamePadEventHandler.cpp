#define GAME_PAD_TEST 0

#include "GamePadEventHandler.h"

#if GAME_PAD_TEST
#include <iostream>
#endif

#include "Postmaster/PostMaster.h"
#include "Postmaster/MessageType.h"
#include "Postmaster/Message.h"

#include "GamePadDefinitions.h"
#include <SFML/Window/Event.hpp>


namespace Platy
{
	namespace Game
	{
		bool GamePadEventHandler::myWasLeftDPad;
		bool GamePadEventHandler::myWasUpDPad;

		float GamePadEventHandler::myDeadZone;

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
				PostMaster::SendMessage(EMessageType::GAME_PAD_CONNECTED);
				break;
			case sf::Event::JoystickDisconnected:
				PostMaster::SendMessage(EMessageType::GAME_PAD_DISCONNECTED);
				break;
			default:
				break;
			}
		}

		void GamePadEventHandler::SetDeadZone(const float& aValue)
		{
			myDeadZone = aValue;
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
			case GAME_PAD_OPTION:
				PostMaster::SendMessage(EMessageType::GAME_PAD_OPTION_PRESSED);
				break;
			case GAME_PAD_START:
				PostMaster::SendMessage(EMessageType::GAME_PAD_START_PRESSED);
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
#if GAME_PAD_TEST
			std::cout << "Button id: " << GamePadIdToCharPtr(anEvent.joystickButton.button) << " pressed" << std::endl;
#endif
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
			case GAME_PAD_OPTION:
				PostMaster::SendMessage(EMessageType::GAME_PAD_OPTION_RELEASED);
				break;
			case GAME_PAD_START:
				PostMaster::SendMessage(EMessageType::GAME_PAD_START_RELEASED);
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
#if GAME_PAD_TEST
			std::cout << "Button id: " << GamePadIdToCharPtr(anEvent.joystickButton.button) << " released" << std::endl;
#endif
		}

		void GamePadEventHandler::HandleJoystickMoved(const sf::Event& anEvent)
		{
			Message tempMessage;
			switch (anEvent.joystickMove.axis)
			{
			case sf::Joystick::X: // Left stick left/right
				if (anEvent.joystickMove.position >= myDeadZone || anEvent.joystickMove.position <= -myDeadZone)
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f);
				}
				else
				{
					tempMessage.SetFloat(0);
				}
				PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_LS_LR_CHANGED);
				break;
			case sf::Joystick::Y: // Left stick up/down
				if (anEvent.joystickMove.position >= myDeadZone || anEvent.joystickMove.position <= -myDeadZone)
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f);
				}
				else
				{
					tempMessage.SetFloat(0);
				}
				PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_LS_UD_CHANGED);
				break;

				// This may be buggy as SFML put the triggers on the same axis. This will not be fixed by the developers, sadly
			case sf::Joystick::Z: // Triggers
				if (anEvent.joystickMove.position < -myDeadZone) // RT < 0
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f * -1);
					PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_RT_CHANGED);
				}
				else if (anEvent.joystickMove.position > myDeadZone) // LT > 0
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f);
					PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_LT_CHANGED);
				}
				else
				{
					tempMessage.SetFloat(0);
					PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_RT_CHANGED);
					PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_LT_CHANGED);
				}
				break;
			case sf::Joystick::R:
				// Don't know what this does
				break;
			case sf::Joystick::U: // Right stick left/right
				if (anEvent.joystickMove.position >= myDeadZone || anEvent.joystickMove.position <= -myDeadZone)
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f);
				}
				else
				{
					tempMessage.SetFloat(0);
				}
				PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_RS_LR_CHANGED);
				break;
			case sf::Joystick::V: // Right stick up/down
				if (anEvent.joystickMove.position >= myDeadZone || anEvent.joystickMove.position <= -myDeadZone)
				{
					tempMessage.SetFloat(anEvent.joystickMove.position / 100.f);
				}
				else
				{
					tempMessage.SetFloat(0);
				}
				PostMaster::SendMessage(tempMessage, EMessageType::GAME_PAD_RS_UD_CHANGED);
				break;
			case sf::Joystick::PovX:
				if (anEvent.joystickMove.position < 0) // D-Pad Left
				{
					myWasLeftDPad = true;
					PostMaster::SendMessage(EMessageType::GAME_PAD_DP_L_PRESSED);
				}
				else if (anEvent.joystickMove.position > 0) // D-Pad Right
				{
					myWasLeftDPad = false;
					PostMaster::SendMessage(EMessageType::GAME_PAD_DP_R_PRESSED);
				}
				else
				{
					if (myWasLeftDPad)
					{
						PostMaster::SendMessage(EMessageType::GAME_PAD_DP_L_RELEASED);
					}
					else
					{
						PostMaster::SendMessage(EMessageType::GAME_PAD_DP_R_RELEASED);
					}
				}
				break;
			case sf::Joystick::PovY: // D-Pad up/down

				if (anEvent.joystickMove.position < 0) // D-Pad Down
				{
					myWasUpDPad = false;
					PostMaster::SendMessage(EMessageType::GAME_PAD_DP_D_PRESSED);
				}
				else if (anEvent.joystickMove.position > 0) // D-Pad Up
				{
					myWasUpDPad = true;
					PostMaster::SendMessage(EMessageType::GAME_PAD_DP_U_PRESSED);
				}
				else
				{
					if (myWasUpDPad)
					{
						PostMaster::SendMessage(EMessageType::GAME_PAD_DP_U_RELEASED);
					}
					else
					{
						PostMaster::SendMessage(EMessageType::GAME_PAD_DP_D_RELEASED);
					}
				}
				break;
			}
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
			case GAME_PAD_OPTION:
				return "OPTION";
			case GAME_PAD_START:
				return "START";
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
