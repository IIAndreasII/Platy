//#ifndef UI_BUTTON_H
//#define UI_BUTTON_H
//
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Text.hpp>
//#include <SFML/System/Vector2.hpp>
//
//#include "Postmaster/Subscriber.h"
//
//
//constexpr float OUTLINE_THICKNESS = 3.f;
//constexpr float TEXT_OFFSET_X = 20;
//constexpr float TEXT_OFFSET_Y = 0;
//
//constexpr unsigned DEFAULT_BUTTON_WIDTH = 100;
//constexpr unsigned DEFAULT_BUTTON_HEIGHT = 45;
//
//
//template <class C>
//class UIButton : public Subscriber, public sf::Drawable
//{
//public:
//	UIButton();
//	UIButton(const char* aText, void (C::* aFunc)(), C* aClassPtr, sf::Vector2f aPosition, bool isActive = true);
//	~UIButton();
//
//	void ReceiveMessage(const Message& aMessage, const Message::EType& aMessageType) override;
//
//	void SetActive(bool aValue);
//
//	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
//
//private:
//
//	bool myIsActive;
//
//	void (C::* myFunction)();
//	C* myClassPtr;
//	sf::Text myText;
//	sf::RectangleShape myRect;
//};
//
//#endif
