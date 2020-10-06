#include "Message.h"

Message::Message() :
	myFloat(),
	myInt(),
	myWidth(),
	myHeight(),
	myBool(false)
{
}

Message::Message(const sf::Vector2i& aPosition) :
	myPosition(aPosition),
	myFloat(),
	myInt(),
	myWidth(),
	myHeight(),
	myBool(false)
{
}

Message::Message(const sf::Vector2i& aPosition, const int aWidth, const int aHeight) :
	myPosition(aPosition),
	myFloat(),
	myInt(),
	myWidth(aWidth),
	myHeight(aHeight),
	myBool(false)
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

sf::Vector2i Message::GetSize() const
{
	return {myWidth, myHeight};
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
