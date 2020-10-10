#ifndef GAME_PAD_EVENT_HANDLER_H
#define GAME_PAD_EVENT_HANDLER_H

namespace sf
{
	class Event;
}

namespace Platy
{
	namespace Game
	{
		class GamePadEventHandler
		{
		public:
			GamePadEventHandler() = delete;
			~GamePadEventHandler() = default;

			static void HandleEvent(const sf::Event& anEvent);

		private:

			static void HandleButtonPressed(const sf::Event& anEvent);
			static void HandleButtonReleased(const sf::Event& anEvent);
			static void HandleJoystickMoved(const sf::Event& anEvent);
			static void HandleConnected(const sf::Event& anEvent);
			static void HandleDisconnected(const sf::Event& anEvent);

			static const char* GamePadIdToCharPtr(const unsigned& id);

			static bool myWasLeftDPad;
			static bool myWasUpDPad;
		};
	}
}
#endif
