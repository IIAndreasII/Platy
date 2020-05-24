#ifndef POSTMASTER_H
#define POSTMASTER_H

#include <vector>

enum EMessageType;

class Message;
class Subscriber;

typedef Subscriber* SubPtr;

class PostMaster
{
public:
	~PostMaster();

	static void Init();

	static void Subscribe(SubPtr aSubPtr, const EMessageType aEMessageType);

	static void Unsubscribe(SubPtr aSubptr, const EMessageType aEMessageType);

	static void SendMessage(const Message& aMessage, const EMessageType& aEMessageType);

	static void SendMessage(EMessageType aEMessageType);

	static std::vector<SubPtr>& GetSubscribers(const EMessageType aMessage);


private:
	PostMaster();

	static std::vector<std::vector<SubPtr>> mySubscribers;

};

#endif