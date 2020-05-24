#ifndef PLAYER_H
#define PLAYER_H

#include "..\Super\Entity.h"
#include "..\Postmaster\Subscriber.h"

enum EMessageType;

class Player : public Entity, public Subscriber
{
public:

	Player();
	~Player();

	void ReceiveMessage(const EMessageType& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) override;

private:


};

#endif