#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/Drawable.hpp>

#include "Platy.Game.Core/Postmaster/Subscriber.h"

class MineField;
typedef MineField* MineFieldPtr;

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

	virtual void ReceiveMessage(const Message::Type& aMessageType);
	virtual void ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	State myState;

	MineFieldPtr myActiveMineField;

};

#endif