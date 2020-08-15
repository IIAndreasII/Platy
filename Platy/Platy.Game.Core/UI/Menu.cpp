#include "Menu.h"
#include "UIButton.h"

template<class C>
Menu<C>::Menu()
	: myIsActive(false)
{
}

template<class C>
Menu<C>::~Menu()
{
}

template<class C>
void Menu<C>::AddButton(const UIButton<C> aButton)
{
	myButtons.push_back(aButton);
}

template<class C>
void Menu<C>::SetActive(const bool aValue) const
{
	myIsActive = aValue;
	for (UIButton<C> it : myButtons)
	{
		it.SetActive(aValue);
	}
}

template<class C>
void Menu<C>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (myIsActive)
	{
		for (UIButton<C> it : myButtons)
		{
			target.draw(it);
		}
	}
}
