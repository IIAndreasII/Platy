#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics/Drawable.hpp"
#include "Platy.Game.Core/Postmaster/Subscriber.h"

class MineField;

class Game : public sf::Drawable, public Subscriber
{
public:
	Game();
	~Game();

	enum class State
	{
		GameOver,
		Menu,
		Playing,
		Paused
	};

	void Update(const float& deltaTime);

	void ReceiveMessage(const Message::Type& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType) override;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	State myState;

	MineField* myActiveMineField;

};

#endif