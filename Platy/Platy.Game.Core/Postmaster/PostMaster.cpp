#include "PostMaster.h"
#include "Subscriber.h"

std::vector<std::vector<SubPtr>> PostMaster::mySubscribers;

PostMaster::PostMaster() = default;

PostMaster::~PostMaster()
{
	for (const std::vector<SubPtr>& it : mySubscribers)
	{
		for (SubPtr sub : it)
		{
			sub = nullptr;
		}
	}
}

void PostMaster::Init()
{
	for (size_t i = 0; i < static_cast<size_t>(Message::EType::COUNT); i++)
	{
		mySubscribers.emplace_back();
	}
}

void PostMaster::Subscribe(const SubPtr aSubPtr, const Message::EType aMessageType)
{
	mySubscribers.at(static_cast<size_t>(aMessageType)).push_back(aSubPtr);
}

void PostMaster::Unsubscribe(SubPtr aSubPtr, const Message::EType aMessageType)
{
	mySubscribers.at(static_cast<size_t>(aMessageType)).erase(std::find(
		mySubscribers.at(static_cast<size_t>(aMessageType)).begin(),
		mySubscribers.at(static_cast<size_t>(aMessageType)).end(),
		aSubPtr));
}

void PostMaster::SendMessage(const Message& aMessage, const Message::EType& type)
{
	for (SubPtr tempSub : mySubscribers.at(static_cast<size_t>(type)))
	{
		if (tempSub != nullptr)
		{
			tempSub->ReceiveMessage(aMessage, type);
		}
	}
}

void PostMaster::SendMessage(Message::EType aMessageType)
{
	for (SubPtr it : mySubscribers.at(static_cast<size_t>(aMessageType)))
	{
		if (it != nullptr)
		{
			it->ReceiveMessage(aMessageType);
		}
	}
}

std::vector<SubPtr>& PostMaster::GetSubscribers(const Message::EType aMessageType)
{
	return mySubscribers.at(static_cast<size_t>(aMessageType));
}
