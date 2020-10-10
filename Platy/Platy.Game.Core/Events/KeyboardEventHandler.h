#ifndef KEYBOARD_EVENT_HANDLER_H
#define KEYBOARD_EVENT_HANDLER_H

// TODO: Add message codes for each key I want in the game, i.e w,a,s d

namespace sf
{
	class Event;
}

namespace Platy
{
	namespace Game
	{
		class KeyboardEventHandler
		{
		public:
			KeyboardEventHandler() = delete;
			~KeyboardEventHandler() = default;

			static void HandleEvent(const sf::Event& anEvent);
		};
	}
}
#endif
