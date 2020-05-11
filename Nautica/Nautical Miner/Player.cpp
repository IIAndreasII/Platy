#include "pch.h"
#include "Player.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::ReceiveMessage(const EMessageType& aMessageType)
{
	switch (aMessageType)
	{
		default:
			break;
	}
}

void Player::ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType)
{
	switch (aMessageType)
	{
		default:
			break;
	}
}
