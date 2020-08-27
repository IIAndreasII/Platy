#include "PostMaster.h"
#include "Subscriber.h"
#include "Message.h"

std::vector<std::vector<SubPtr>> PostMaster::mySubscribers;

PostMaster::PostMaster()
{
}

PostMaster::~PostMaster()
{
	for (auto it : mySubscribers)
	{
		for (SubPtr sub : it)
		{
			sub = NULL;
		}
	}
}

void PostMaster::Init()
{
	for (size_t i = 0; i < static_cast<int>(Message::Type::COUNT); i++)
	{
		mySubscribers.push_back(std::vector<SubPtr>());
	}
}

void PostMaster::Subscribe(SubPtr aSubPtr, const Message::Type aMessage)
{
	mySubscribers.at(static_cast<int>(aMessage)).push_back(aSubPtr);
}

void PostMaster::Unsubscribe(SubPtr aSubptr, const Message::Type type)
{
	mySubscribers.at(static_cast<int>(type)).erase(std::find(mySubscribers.at(static_cast<int>(type)).begin(), mySubscribers.at(static_cast<int>(type)).end(), aSubptr));
}

void PostMaster::SendMessage(const Message& aMessage, const Message::Type& type)
{
	for (SubPtr tempSub : mySubscribers.at(static_cast<int>(type)))
	{
		if (tempSub != NULL)
		{
			tempSub->ReceiveMessage(aMessage, type);
		}
	}
}

void PostMaster::SendMessage(Message::Type type)
{
	for (SubPtr it : mySubscribers.at(static_cast<int>(type)))
	{
		if (it != NULL)
		{
			it->ReceiveMessage(type);
		}
	}
}

std::vector<SubPtr>& PostMaster::GetSubscribers(const Message::Type type)
{
	return mySubscribers.at(static_cast<int>(type));
}