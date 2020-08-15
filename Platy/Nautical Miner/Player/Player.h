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

	void Update(const float& deltaTime) override;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	void ReceiveMessage(const EMessageType& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const EMessageType& aMessageType) override;

private:

	void HandleInput(const EMessageType& aMessageType);


	float myWalkSpeed;
	int myDirection;

};

#endif