#ifndef UIBUTTON_H
#define UIBUTTON_H

#include "SFML/Graphics/Text.hpp"
#include "..\Postmaster\Subscriber.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

constexpr float OUTLINE_THICKNESS = 3.f;
constexpr float TEXT_OFFSET_X = 20;
constexpr float TEXT_OFFSET_Y = 0;

constexpr unsigned DEFAULT_BUTTON_WIDTH = 100;
constexpr unsigned DEFAULT_BUTTON_HEIGHT = 45;


template<class C>
class UIButton : public Subscriber, public sf::Drawable
{
public:
	UIButton();
	UIButton(const char* aText, void(C::* aFunc)(), C* aClassPtr, const sf::Vector2f aPosition, const bool isActive = true);
	~UIButton();

	void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) override;

	void SetActive(const bool aValue);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	bool myIsActive;

	void(C::* myFunction)();
	C* myClassPtr;

	sf::Text myText;
	sf::RectangleShape myRect;
};

#endif