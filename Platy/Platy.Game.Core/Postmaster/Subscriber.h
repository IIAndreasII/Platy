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

	void SendMessage(const Message& aMessage, const Message::Type aMessageType);

	void SendMessage(const Message::Type aMessageType);

	virtual void ReceiveMessage(const Message::Type& aMessageType);
	virtual void ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType);

	void Subscribe(const Message::Type aMessageType);
	void RemoveAllSubscriptions();

	const std::vector<Message::Type>& GetSubscriptions();

protected:

	std::vector<Message::Type> mySubscriptions;

};

#endif