#ifndef SUB_H
#define SUB_H

#include <vector>
#include "Message.h"

class Message;

class Subscriber
{
public:
	Subscriber();
	virtual ~Subscriber();

	void SendMessage(const Message& aMessage, Message::EType aMessageType) const;

	void SendMessage(Message::EType aMessageType) const;

	virtual void ReceiveMessage(const Message::EType& aMessageType) = 0;
	virtual void ReceiveMessage(const Message& aMessage, const Message::EType& aMessageType) = 0;

	void Subscribe(Message::EType aMessageType);
	void RemoveAllSubscriptions();

	const std::vector<Message::EType>& GetSubscriptions() const;

protected:

	std::vector<Message::EType> mySubscriptions;
};

#endif
