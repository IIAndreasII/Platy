#include "Subscriber.h"
#include "PostMaster.h"

Subscriber::Subscriber()
{
}

Subscriber::~Subscriber()
{
}

void Subscriber::SendMessage(const Message& aMessage, const Message::Type aMessageType)
{
	PostMaster::SendMessage(aMessage, aMessageType);
}

void Subscriber::SendMessage(const Message::Type aMessageType)
{
	PostMaster::SendMessage(aMessageType);
}

void Subscriber::ReceiveMessage(const Message::Type& aMessageType)
{
}

void Subscriber::ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType)
{
}

void Subscriber::Subscribe(const Message::Type aMessageType)
{
	if (!(std::find(mySubscriptions.begin(), mySubscriptions.end(), aMessageType) != mySubscriptions.end()))
	{
		mySubscriptions.push_back(aMessageType);
		PostMaster::Subscribe(this, aMessageType);
	}
}

void Subscriber::RemoveAllSubscriptions()
{
	for (Message::Type tempMsgType : mySubscriptions)
	{
		PostMaster::Unsubscribe(this, tempMsgType);
	}
}

const std::vector<Message::Type>& Subscriber::GetSubscriptions()
{
	return mySubscriptions;
}