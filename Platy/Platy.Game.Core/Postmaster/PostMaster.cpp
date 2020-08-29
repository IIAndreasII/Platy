#include "PostMaster.h"
#include "Subscriber.h"
#include "Message.h"

std::vector<std::vector<SubPtr>> PostMaster::mySubscribers;

PostMaster::PostMaster()
{
}

PostMaster::~PostMaster()
{
	for (std::vector<SubPtr> it : mySubscribers)
	{
		for (SubPtr sub : it)
		{
			sub = NULL;
		}
	}
}

void PostMaster::Init()
{
	for (size_t i = 0; i < (size_t)Message::Type::COUNT; i++)
	{
		mySubscribers.push_back(std::vector<SubPtr>());
	}
}

void PostMaster::Subscribe(SubPtr aSubPtr, const Message::Type aMessage)
{
	mySubscribers.at((size_t)aMessage).push_back(aSubPtr);
}

void PostMaster::Unsubscribe(SubPtr aSubptr, const Message::Type type)
{
	mySubscribers.at((size_t)type).erase(std::find(mySubscribers.at((size_t)type).begin(), mySubscribers.at((size_t)type).end(), aSubptr));
}

void PostMaster::SendMessage(const Message& aMessage, const Message::Type& type)
{
	for (SubPtr tempSub : mySubscribers.at((size_t)type))
	{
		if (tempSub != NULL)
		{
			tempSub->ReceiveMessage(aMessage, type);
		}
	}
}

void PostMaster::SendMessage(Message::Type type)
{
	for (SubPtr it : mySubscribers.at((size_t)type))
	{
		if (it != NULL)
		{
			it->ReceiveMessage(type);
		}
	}
}

std::vector<SubPtr>& PostMaster::GetSubscribers(const Message::Type type)
{
	return mySubscribers.at((size_t)type);
}