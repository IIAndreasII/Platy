#include "pch.h"
#include "Subscriber.h"
#include "PostMaster.h"
#include "Message.h"

Subscriber::Subscriber()
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::SendMessage(const Message& aMessage, const EMessageType aMessageType)
{
	PostMaster::SendMessage(aMessage, aMessageType);
}

void Subscriber::SendMessage(const EMessageType aMessageType)
{
	PostMaster::SendMessage(aMessageType);
}

void Subscriber::ReceiveMessage(const EMessageType& aMessageType)
{
}

void Subscriber::ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType)
{
}

void Subscriber::Subscribe(const EMessageType aMessageType)
{
	if (!(std::find(mySubscriptions.begin(), mySubscriptions.end(), aMessageType) != mySubscriptions.end()))
	{
		mySubscriptions.push_back(aMessageType);
		PostMaster::Subscribe(this, aMessageType);
	}
}

void Subscriber::RemoveAllSubscriptions()
{
	for (EMessageType tempMsgType : mySubscriptions)
	{
		PostMaster::Unsubscribe(this, tempMsgType);
	}
}

std::vector<EMessageType>& Subscriber::GetSubscriptions()
{
	return mySubscriptions;
}