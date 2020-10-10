#ifndef SUB_H
#define SUB_H

#include <vector>

namespace Platy
{
	namespace Game
	{
		class Message;
		enum class EMessageType;

		class Subscriber
		{
		public:
			Subscriber();
			virtual ~Subscriber();

			void SendMessage(const Message& aMessage, EMessageType aMessageType) const;

			void SendMessage(EMessageType aMessageType) const;

			virtual void ReceiveMessage(const EMessageType& aMessageType) = 0;
			virtual void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) = 0;

			void Subscribe(EMessageType aMessageType);
			void RemoveAllSubscriptions();

			const std::vector<EMessageType>& GetSubscriptions() const;

		protected:

			std::vector<EMessageType> mySubscriptions;
		};
	}
}
#endif
