#ifndef POSTMASTER_H
#define POSTMASTER_H

#include <vector>
#include "Message.h"

class Subscriber;

typedef Subscriber* SubPtr;

class PostMaster
{
public:
	~PostMaster();

	static void Init();

	static void Subscribe(SubPtr aSubPtr, const Message::Type aEMessageType);

	static void Unsubscribe(SubPtr aSubptr, const Message::Type aEMessageType);

	static void SendMessage(const Message& aMessage, const Message::Type& aEMessageType);

	static void SendMessage(Message::Type aEMessageType);

	static std::vector<SubPtr>& GetSubscribers(const Message::Type aMessage);

private:
	PostMaster();

	static std::vector<std::vector<SubPtr>> mySubscribers;

};

#endif