#include "PostMaster.h"

#include "Subscriber.h"
#include "Message.h"
#include "MessageType.h"

namespace Platy
{
	namespace Game
	{
		std::vector<std::vector<SubPtr>> PostMaster::mySubscribers;

		PostMaster::~PostMaster()
		{
			for (const auto& it : mySubscribers)
			{
				for (auto* sub : it)
				{
					sub = nullptr;
				}
			}
		}

		void PostMaster::Init()
		{
			for (size_t i = 0; i < static_cast<size_t>(EMessageType::COUNT); i++)
			{
				mySubscribers.emplace_back();
			}
		}

		void PostMaster::Subscribe(const SubPtr aSubPtr, const EMessageType aMessageType)
		{
			mySubscribers.at(static_cast<size_t>(aMessageType)).push_back(aSubPtr);
		}

		void PostMaster::Unsubscribe(const SubPtr aSubPtr, const EMessageType aMessageType)
		{
			mySubscribers.at(static_cast<size_t>(aMessageType)).erase(std::find(
				mySubscribers.at(static_cast<size_t>(aMessageType)).begin(),
				mySubscribers.at(static_cast<size_t>(aMessageType)).end(),
				aSubPtr));
		}

		void PostMaster::SendMessage(const Message& aMessage, EMessageType aMessageType)
		{
			for (auto* it : mySubscribers.at(static_cast<size_t>(aMessageType)))
			{
				if (it)
				{
					it->ReceiveMessage(aMessage, aMessageType);
				}
			}
		}

		void PostMaster::SendMessage(EMessageType aMessageType)
		{
			for (auto* it : mySubscribers.at(static_cast<size_t>(aMessageType)))
			{
				if (it)
				{
					it->ReceiveMessage(aMessageType);
				}
			}
		}

		std::vector<SubPtr>& PostMaster::GetSubscribers(const EMessageType aMessageType)
		{
			return mySubscribers.at(static_cast<size_t>(aMessageType));
		}
	}
}
