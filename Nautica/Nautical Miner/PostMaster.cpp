#include "pch.h"
#include "PostMaster.h"
#include "Subscriber.h"
#include "Message.h"
#include "Enums.h"

std::vector<std::vector<SubPtr>> PostMaster::mySubscribers;

PostMaster::PostMaster()
{
}

PostMaster::~PostMaster()
{
}

void PostMaster::Init()
{
	for (size_t i = 0; i < EMessageType::COUNT; i++)
	{
		mySubscribers.push_back(std::vector<SubPtr>());
	}
}

void PostMaster::Subscribe(SubPtr aSubPtr, const EMessageType aMessage)
{
	mySubscribers.at(aMessage).push_back(aSubPtr);
}

void PostMaster::Unsubscribe(SubPtr aSubptr, const EMessageType aEMessageType)
{
	mySubscribers.at(aEMessageType).erase(std::find(mySubscribers.at(aEMessageType).begin(), mySubscribers.at(aEMessageType).end(), aSubptr));
}

void PostMaster::ReceiveMessage(Message& aMessage, EMessageType aEMessageType)
{
	for (SubPtr tempSub : mySubscribers.at(aEMessageType))
	{
		if (tempSub != nullptr)
		{
			tempSub->ReceiveMessage(aMessage, aEMessageType);
		}
	}
}

void PostMaster::ReceiveMessage(EMessageType aEMessageType)
{
	for (SubPtr tempSub : mySubscribers.at(aEMessageType))
	{
		if (tempSub != nullptr)
		{
			tempSub->ReceiveMessage(aEMessageType);
		}
	}
}

std::vector<Subscriber*>& PostMaster::GetSubscribers(const EMessageType aMessage)
{
	return mySubscribers.at(aMessage);
}