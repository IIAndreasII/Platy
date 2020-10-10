//#ifndef BUTTON_H
//#define BUTTON_H
//
//#include <SFML/Graphics/RectangleShape.hpp>
//#include <SFML/Graphics/Text.hpp>
//
//
//#include "Postmaster/MessageType.h"
//#include "Postmaster/Subscriber.h"
//#include "SFML/Graphics/Drawable.hpp"
//
//namespace Platy
//{
//	namespace Game
//	{
//		class Button final : public Subscriber, public sf::Drawable
//		{
//		public:
//			Button(sf::Vector2f aPosition, sf::Vector2f aSize, const std::string& someText, std::string aFontName,
//			       sf::Texture* aTexture, sf::Texture* aHoveredTexture);
//			Button(sf::Vector2f aPosition, sf::Vector2f aSize, const std::string& someText, std::string aFontName);
//			~Button() override;
//			void SetMessage(EMessageType aMessageType);
//
//			void ReceiveMessage(const EMessageType& aMessageType) override;
//			void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) override;
//
//			void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//
//		private:
//
//			bool myUseTextures;
//
//			EMessageType myMessageType;
//
//			sf::RectangleShape myRect;
//			sf::Text myText;
//
//			sf::Texture* myTexture;
//			sf::Texture* myHoveredTexture;
//		};
//	}
//}
//#endif
