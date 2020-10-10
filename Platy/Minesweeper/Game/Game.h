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
	~Game() override;

	enum class EState
	{
		GameOver,
		Menu,
		Playing,
		Paused
	};

	void Update(const float& someDeltaTime);

	void ReceiveMessage(const Message::EType& aMessageType) override;
	void ReceiveMessage(const Message& aMessage, const Message::EType& aMessageType) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	EState myState;

	sf::Text myMineCounterText;
	sf::Text myTimeCounterText;

	MineField::ESize myChosenDifficulty = MineField::ESize::HARD;

	MineFieldPtr myActiveMineField = nullptr;

	void ResetMineField();
	void UpdateMineCounterText();
	void UpdateTimeCounterText();
};

#endif
