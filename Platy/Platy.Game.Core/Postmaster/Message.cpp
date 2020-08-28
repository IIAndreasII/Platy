#include "Message.h"

Message::Message() :
	myBool(false),
	myFloat(),
	myInt(),
	myWidth(),
	myHeight(),
	myPosition()
{
}

Message::Message(const sf::Vector2i& aPosition) : 
	myBool(false),
	myFloat(),
	myInt(),
	myWidth(),
	myHeight(),
	myPosition(aPosition)
{
}

Message::Message(const sf::Vector2i& aPosition, const int aWidth, const int aHeight) :
	myBool(false),
	myFloat(),
	myInt(),
	myWidth(aWidth),
	myHeight(aHeight),
	myPosition(aPosition)
{
}

Message::~Message()
{
}

void Message::SetFloat(const float aValue)
{
	myFloat = aValue;
}

void Message::SetInt(const int aValue)
{
	myInt = aValue;
}

void Message::SetBool(const bool aValue)
{
	myBool = aValue;
}

const sf::Vector2i& Message::GetPosition() const
{
	return myPosition;
}

const sf::Vector2i Message::GetSize() const
{
	return sf::Vector2i(myWidth, myHeight);
}

const int& Message::GetInt() const
{
	return myInt;
}

const float& Message::GetFloat() const
{
	return myFloat;
}

const bool& Message::GetBool() const
{
	return myBool;
}
