#ifndef PM_H
#define PM_H

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

	static void ReceiveMessage(Message& aMessage, EMessageType aEMessageType);

	static void ReceiveMessage(EMessageType aEMessageType);

	static std::vector<SubPtr>& GetSubscribers(const EMessageType aMessage);


private:
	PostMaster();

	static std::vector<std::vector<SubPtr>> mySubscribers;


};

#endif // !1