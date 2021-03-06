//#include "Button.h"
//
//#include "Postmaster/Message.h"
//#include "Postmaster/MessageType.h"
//
//#include <iostream>
//#include <utility>
//#include <Containers/AssetContainer.h>
//#include <Graphics/Colors.h>
//#include <SFML/Graphics/RenderStates.hpp>
//#include <SFML/Graphics/RenderTarget.hpp>
//
//
//namespace Platy
//{
//	namespace Game
//	{
//		Button::Button(const sf::Vector2f aPosition, const sf::Vector2f aSize, const std::string& someText,
//		               std::string aFontName,
//		               sf::Texture* aTexture, sf::Texture* aHoveredTexture)
//			:
//			myUseTextures(true),
//			myMessageType(),
//			myRect(aSize),
//			myText(someText, *AssetContainer::GetFontPtr(std::move(aFontName))),
//			myTexture(aTexture),
//			myHoveredTexture(aHoveredTexture)
//		{
//			myRect.setPosition(aPosition);
//			myRect.setTexture(myTexture);
//		}
//
//		Button::Button(const sf::Vector2f aPosition, const sf::Vector2f aSize, const std::string& someText,
//		               std::string aFontName)
//			:
//			myUseTextures(false),
//			myMessageType(),
//			myRect(aSize),
//			myText(someText, *AssetContainer::GetFontPtr(std::move(aFontName))),
//			myTexture(nullptr),
//			myHoveredTexture(nullptr)
//		{
//			myRect.setPosition(aPosition);
//
//			myRect.setFillColor(C_CYAN_DARK);
//			myRect.setOutlineColor(C_CYAN);
//		}
//
//		Button::~Button()
//		{
//			RemoveAllSubscriptions();
//			myTexture = nullptr;
//			myHoveredTexture = nullptr;
//		}
//
//		void Button::SetMessage(const EMessageType aMessageType)
//		{
//			myMessageType = aMessageType;
//		}
//
//		void Button::ReceiveMessage(const EMessageType& aMessageType)
//		{
//		}
//
//		void Button::ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType)
//		{
//			// Check mouse intersection
//			const auto tempIsMouseHovering = myRect.getTextureRect().intersects(
//				sf::Rect<int>(aMessage.GetPosition(), sf::Vector2i(1, 1)));
//
//			switch (aMessageType)
//			{
//			case EMessageType::MOUSE_ON_CLICK_LEFT:
//				if (tempIsMouseHovering)
//				{
//					SendMessage(myMessageType);
//					std::cout << "I was pressed!" << std::endl;
//				}
//				break;
//
//			case EMessageType::MOUSE_MOVED:
//
//				if (tempIsMouseHovering)
//				{
//					if (myUseTextures)
//					{
//						myRect.setTexture(myTexture);
//					}
//					else
//					{
//						myRect.setOutlineThickness(5);
//					}
//				}
//				else
//				{
//					if (myUseTextures)
//					{
//						myRect.setTexture(myHoveredTexture);
//					}
//					else
//					{
//						myRect.setOutlineThickness(0);
//					}
//				}
//				break;
//
//			default:
//				break;
//			}
//		}
//
//		void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
//		{
//			target.draw(myRect);
//			target.draw(myText);
//		}
//	}
//}
