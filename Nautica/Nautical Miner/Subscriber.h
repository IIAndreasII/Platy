#ifndef SUB_H
#define SUB_H

#include <vector>

enum EMessageType;
class Message;

class Subscriber
{
public:
	Subscriber();
	virtual ~Subscriber();

	void SendMessage(Message& aMessage, const EMessageType aMessageType);

	void SendMessage(const EMessageType aMessageType);

	virtual void ReceiveMessage(const EMessageType& aMessageType);
	virtual void ReceiveMessage(Message& aMessage, const EMessageType& aMessageType);

	void Subscribe(const EMessageType aMessageType);
	void RemoveAllSubscriptions();

	std::vector<EMessageType>& GetSubscriptions();

protected:

	std::vector<EMessageType> mySubbedMessages;


};

#endif