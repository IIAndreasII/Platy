#ifndef MESSAGE_H
#define MESSAGE_H

enum EMessageType
{
	TOGGLE_PAUSE,
	COUNT // Not to be used as a type
};

class Message
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