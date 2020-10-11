#ifndef POST_MASTER_H
#define POST_MASTER_H

#include <vector>

namespace Platy
{
	namespace Game
	{
		class Message;
		class Subscriber;

		enum class EMessageType;

		class PostMaster
		{
		public:
			PostMaster() = delete;
			~PostMaster();

			static void Init();

			static void Subscribe(Subscriber* aSubPtr, EMessageType aMessageType);

			static void Unsubscribe(const Subscriber* aSubPtr, EMessageType aMessageType);
			static void SendMessage(const Message& aMessage, EMessageType aMessageType);

			static void SendMessage(EMessageType aMessageType);

			static std::vector<Subscriber*>& GetSubscribers(EMessageType aMessageType);

		private:

			static std::vector<std::vector<Subscriber*>> mySubscribers;
		};
	}
}

#endif
