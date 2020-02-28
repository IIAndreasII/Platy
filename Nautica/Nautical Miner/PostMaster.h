#ifndef PM_H
#define PM_H

#include <vector>

enum EMessageType;

class Message;
class Subscriber;

class PostMaster
{
public:
	~PostMaster();

	static void Init();

	static void Subscribe(Subscriber* aSubPtr, const EMessageType aEMessageType);

	static void Unsubscribe(Subscriber* aSubptr, const EMessageType aEMessageType);

	static void ReceiveMessage(Message& aMessage, EMessageType aEMessageType);

	static void ReceiveMessage(EMessageType aEMessageType);

	static std::vector<Subscriber*>& GetSubscribers(const EMessageType aMessage);


private:
	PostMaster();

	static std::vector<std::vector<Subscriber*>> mySubscribers;


};

#endif // !1