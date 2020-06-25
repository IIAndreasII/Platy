#include "..\pch.h"
#include "UIButton.h"
#include "..\Postmaster\Message.h"
#include "..\Containers\AssetContainer.h"
#include "..\Util\Colors.h"


template<class C>
UIButton<C>::UIButton()
{
	Subscribe(EMessageType::MOUSE_ON_CLICK_LEFT);
	Subscribe(EMessageType::MOUSE_MOVED);
}

template<class C>
UIButton<C>::UIButton(const char* aText, void(C::* aFunc)(), C* aClassPtr, const sf::Vector2f aPosition, const bool isActive)
	: myText(aText, *AssetContainer::GetFontPtr("firstorder")),
	myFunction(aFunc),
	myClassPtr(aClassPtr),
	myRect(sf::Vector2f(DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT)),
	myIsActive(isActive)
{
	Subscribe(EMessageType::MOUSE_ON_CLICK_LEFT);
	Subscribe(EMessageType::MOUSE_MOVED);

	myText.setPosition(aPosition.x + TEXT_OFFSET_X, aPosition.y + TEXT_OFFSET_Y);
	myText.setFillColor(C_BLACK);

	myRect.setPosition(aPosition);
	myRect.setOutlineColor(C_RÅSA);
	myRect.setFillColor(C_RÅSA);
	myRect.setOutlineThickness(OUTLINE_THICKNESS);
}

template<class C>
UIButton<C>::~UIButton()
{
	myFunction = NULL;
	myClassPtr = NULL;
	RemoveAllSubscriptions();
}

template<class C>
void UIButton<C>::ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType)
{
	if (myIsActive)
	{
		switch (aMessageType)
		{
		case EMessageType::MOUSE_ON_CLICK_LEFT:
			if ((sf::IntRect(myRect.getPosition().x, myRect.getPosition().y, myRect.getSize().x, myRect.getSize().y)).intersects(sf::IntRect(aMessage.GetPosition(), sf::Vector2i(1, 1))))
			{
				(myClassPtr->*myFunction)();
			}
			break;

		case EMessageType::MOUSE_MOVED:
			if ((sf::IntRect(myRect.getPosition().x, myRect.getPosition().y, myRect.getSize().x, myRect.getSize().y)).intersects(sf::IntRect(aMessage.GetPosition(), sf::Vector2i(1, 1))))
			{
				myRect.setOutlineColor(C_AMETIST);
			}
			else
			{
				myRect.setOutlineColor(C_RÅSA);
			}

		default:
			break;
		}
	}
}

template<class C>
void UIButton<C>::SetActive(const bool aValue)
{
	myIsActive = aValue;
}

template<class C>
void UIButton<C>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;
	target.draw(myRect, states);
	target.draw(myText, states);
}
