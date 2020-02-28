#ifndef MESSAGE_H
#define MESSAGE_H


enum EMessageType;

struct Message
{
public:

	Message();
	~Message();

	// TODO: Add suitable constructors depending on type
	Message(const EMessageType type);
	
	
	const EMessageType& GetType();

private:

	// TODO: Add suitable members
	EMessageType myType;

};


#endif