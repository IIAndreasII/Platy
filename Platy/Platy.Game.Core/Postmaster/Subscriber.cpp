#include "Subscriber.h"
#include "PostMaster.h"
#include "Message.h"
#include "MessageType.h"

namespace Platy
{
	namespace Game
	{
		Subscriber::Subscriber() = default;

		Subscriber::~Subscriber() = default;

		void Subscriber::SendMessage(const Message& aMessage, const EMessageType aMessageType) const
		{
			PostMaster::SendMessage(aMessage, aMessageType);
		}

		void Subscriber::SendMessage(const EMessageType aMessageType) const
		{
			PostMaster::SendMessage(aMessageType);
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
			for (auto tempMsgType : mySubscriptions)
			{
				PostMaster::Unsubscribe(this, tempMsgType);
			}
		}

		const std::vector<EMessageType>& Subscriber::GetSubscriptions() const
		{
			return mySubscriptions;
		}
	}
}
