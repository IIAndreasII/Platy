#ifndef PLAYER_H
#define PLAYER_H

enum EMessageType;
#include "Entity.h"
#include "Subscriber.h"


class PlayerMotor;

typedef PlayerMotor* PlayerMotorPtr;

class Player : public Entity, public Subscriber
{
public:

	Player();
	~Player();

	void ReceiveMessage(const EMessageType& aMessageType) override;
	void ReceiveMessage(Message& aMessage, const EMessageType& aMessageType) override;

private:

	PlayerMotorPtr myMotor;

};

#endif