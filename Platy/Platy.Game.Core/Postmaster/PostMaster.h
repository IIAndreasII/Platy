#ifndef POSTMASTER_H
#define POSTMASTER_H

#include <vector>
#include "Message.h"

namespace Platy
{
	namespace Game
	{
		class Subscriber;

		typedef Subscriber* SubPtr;

		class PostMaster
		{
		public:
			~PostMaster();

			static void Init();

			static void Subscribe(SubPtr aSubPtr, Message::EType aMessageType);

			static void Unsubscribe(SubPtr aSubPtr, Message::EType aMessageType);

			static void SendMessage(const Message& aMessage, const Message::EType& aMessageType);

			static void SendMessage(Message::EType aMessageType);

			static std::vector<SubPtr>& GetSubscribers(Message::EType aMessageType);

		private:
			PostMaster();

			static std::vector<std::vector<SubPtr>> mySubscribers;
		};
	}
}
#endif
