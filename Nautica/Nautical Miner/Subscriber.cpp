#include "pch.h"
#include "Subscriber.h"
#include "PostMaster.h"
#include "Message.h"
#include "Enums.h"

Subscriber::Subscriber()
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::SendMessage(Message& aMessage, const EMessageType aMessageType)
{
	PostMaster::ReceiveMessage(aMessage, aMessageType);
}

void Subscriber::SendMessage(const EMessageType aMessageType)
{
	PostMaster::ReceiveMessage(aMessageType);
}

void Subscriber::ReceiveMessage(const EMessageType& aMessageType)
{
}

void Subscriber::ReceiveMessage(Message& aMessage, const EMessageType& aMessageType)
{
}

void Subscriber::Subscribe(const EMessageType aMessageType)
{
	if (!(std::find(mySubbedMessages.begin(), mySubbedMessages.end(), aMessageType) != mySubbedMessages.end()))
	{
		mySubbedMessages.push_back(aMessageType);
		PostMaster::Subscribe(this, aMessageType);
	}
}

void Subscriber::RemoveAllSubscriptions()
{
	for (EMessageType tempMsgType : mySubbedMessages)
	{
		PostMaster::Unsubscribe(this, tempMsgType);
	}
}

std::vector<EMessageType>& Subscriber::GetSubscriptions()
{
	return mySubbedMessages;
}