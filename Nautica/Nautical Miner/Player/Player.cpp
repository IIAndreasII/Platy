#include "..\pch.h"
#include "Player.h"
#include "SFML/Graphics/RenderTarget.hpp"
#include "..\Graphics\Animator.h"
#include "..\Postmaster\Message.h"

Player::Player()
	: myWalkSpeed(15.f),
	myDirection(0)
{
	Subscribe(KEY_A_PRESSED);
	Subscribe(KEY_A_RELEASED);
	Subscribe(KEY_D_PRESSED);
	Subscribe(KEY_D_RELEASED);
}

Player::~Player()
{
	RemoveAllSubscriptions();
}

void Player::Update(const float& deltaTime)
{
	
	setPosition(getPosition().x + myDirection * myWalkSpeed * deltaTime, getPosition().y);

	myAnim->Update(deltaTime, getPosition());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*myAnim, states);
}

void Player::ReceiveMessage(const EMessageType& aMessageType)
{
	switch (aMessageType)
	{
		default:
			HandleInput(aMessageType);
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

void Player::HandleInput(const EMessageType& aMessageType) // Handle mouse events too?
{
	switch (aMessageType)
	{
	case EMessageType::KEY_A_PRESSED:
		myAnim->SetFacingDirection(-1);
		myDirection = -1;
		break;

	case EMessageType::KEY_D_PRESSED:
		myAnim->SetFacingDirection(-1);
		myDirection = -1;
		break;

	case EMessageType::KEY_A_RELEASED:
	case EMessageType::KEY_D_RELEASED:
		myDirection = 0;
		break;

	default:
		break;
	}
}
