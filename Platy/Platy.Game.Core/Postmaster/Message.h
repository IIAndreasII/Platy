#ifndef MESSAGE_H
#define MESSAGE_H

#include "SFML/System/Vector2.hpp"

enum EMessageType
{
	MOUSE_ON_CLICK_LEFT,
	MOUSE_ON_CLICK_RIGHT,
	MOUSE_MOVED,
	TOGGLE_PAUSE,
	KEY_A_PRESSED,
	KEY_A_RELEASED,
	KEY_D_PRESSED,
	KEY_D_RELEASED,
	COUNT // Not to be used as a type
};

class Message
{
public:

	Message();
	Message(const sf::Vector2i& aPosition);
	Message(const sf::Vector2i& aPosition, const int aWidth, const int aHeight);
	~Message();

	
	void SetFloat(const float aValue);
	void SetInt(const int aValue);
	void SetBool(const bool aValue);
	
	const sf::Vector2i& GetPosition() const;
	const sf::Vector2i GetSize() const;
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


#endif