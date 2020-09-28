#ifndef MENU_H
#define MENU_H

#include <vector>
#include "SFML/Graphics/Drawable.hpp"

template <class C>
class UIButton;

template <class C>
class Menu : public sf::Drawable
{
public:
	Menu();
	~Menu();

	void AddButton(UIButton<C> aButton);

	void SetActive(bool aValue);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	bool myIsActive;

	std::vector<UIButton<C>> myButtons;
};

#endif
