#ifndef GAME_H
#define GAME_H

#include "MineField.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Platy.Game.Core/Postmaster/Subscriber.h"

typedef MineField* MineFieldPtr;

class Game : public sf::Drawable, public Subscriber
{
public:
	Game();
	~Game();

	enum class EState
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

	EState myState;

	sf::Text myMineCounterText;
	sf::Text myTimeCounterText;

	MineField::Size myChosenDifficulty;

	MineFieldPtr myActiveMineField;

	void ResetMineField();
	void UpdateMineCounterText();
	void UpdateTimeCounterText();
};

#endif