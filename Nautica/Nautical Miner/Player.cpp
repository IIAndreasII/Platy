#include "pch.h"
#include "Player.h"


Player::Player() :
	myMotor()
{
}

Player::~Player()
{
	SafeDelete(myMotor);
}

void Player::ReceiveMessage(const EMessageType& aMessageType)
{
	switch (aMessageType)
	{
		default:
			break;
	}
}

void Player::ReceiveMessage(Message& aMessage, const EMessageType& aMessageType)
{
	switch (aMessageType)
	{
		default:
			break;
	}
}
