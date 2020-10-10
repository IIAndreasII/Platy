#ifndef MOUSE_EVENT_HANDLER_H
#define MOUSE_EVENT_HANDLER_H

// TODO: Add message codes for mouse events

namespace sf
{
	class Event;
	class RenderWindow;
}

namespace Platy
{
	namespace Game
	{
		class MouseEventHandler
		{
		public:
			MouseEventHandler() = delete;
			~MouseEventHandler() = default;

			static void HandleEvent(const sf::Event& anEvent, const sf::RenderWindow& aWindow);
		};
	}
}
#endif
