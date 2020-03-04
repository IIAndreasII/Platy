#include "Message.h"
#include "Enums.h"



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

const EMessageType& Message::GetType()
{
	return myType;
}
