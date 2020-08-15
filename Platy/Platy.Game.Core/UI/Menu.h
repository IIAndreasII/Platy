#ifndef MENU_H
#define MENU_H

#include <vector>
#include "SFML/Graphics/Drawable.hpp"

template<class C>
class UIButton;

template<class C>
class Menu : public sf::Drawable
{
public:
	Menu();
	~Menu();

	void AddButton(const UIButton<C> aButton);

	void SetActive(const bool aValue) const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	 
	bool myIsActive;

	std::vector<UIButton<C>> myButtons;
};

#endif