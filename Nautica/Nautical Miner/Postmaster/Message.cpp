#include "Message.h"
#include "..\Util\Enums.h"



Message::Message()
{
}

Message::Message(const EMessageType type) :
	myType(type)
{
}

Message::~Message()
{
}

const EMessageType& Message::GetType() const
{
	return myType;
}