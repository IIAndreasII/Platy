#ifndef MESSAGE_H
#define MESSAGE_H

#include "SFML/System/Vector2.hpp"

namespace Platy
{
	namespace Game
	{
		class Message
		{
		public:
			Message();
			explicit Message(const sf::Vector2i& aPosition);
			Message(const sf::Vector2i& aPosition, int aWidth, int aHeight);
			~Message() = default;

			void SetFloat(float aValue);
			void SetInt(int aValue);
			void SetBool(bool aValue);

			const sf::Vector2i& GetPosition() const;
			sf::Vector2i GetSize() const;
			const int& GetInt() const;
			const float& GetFloat() const;
			const bool& GetBool() const;

		private:

			sf::Vector2i myPosition;
			float myFloat;
			int myInt,
			    myWidth,
			    myHeight;
			bool myBool;
		};
	}
}
#endif
