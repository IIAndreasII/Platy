#include "Message.h"
#include "Enums.h"

Message::Message() :
	myType(EMessageType::DEFAULT)
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
