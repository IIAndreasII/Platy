#include "Subscriber.h"
#include "PostMaster.h"


Subscriber::Subscriber() = default;

Subscriber::~Subscriber() = default;

void Subscriber::SendMessage(const Message& aMessage, const Message::EType aMessageType) const
{
	PostMaster::SendMessage(aMessage, aMessageType);
}

void Subscriber::SendMessage(const Message::EType aMessageType) const
{
	PostMaster::SendMessage(aMessageType);
}

void Subscriber::Subscribe(const Message::EType aMessageType)
{
	if (!(std::find(mySubscriptions.begin(), mySubscriptions.end(), aMessageType) != mySubscriptions.end()))
	{
		mySubscriptions.push_back(aMessageType);
		PostMaster::Subscribe(this, aMessageType);
	}
}

void Subscriber::RemoveAllSubscriptions()
{
	for (Message::EType tempMsgType : mySubscriptions)
	{
		PostMaster::Unsubscribe(this, tempMsgType);
	}
}

const std::vector<Message::EType>& Subscriber::GetSubscriptions() const
{
	return mySubscriptions;
}
