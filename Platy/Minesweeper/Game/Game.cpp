#include "Game.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "MineField.h"
#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Postmaster/Message.h"

Game::Game() :
	myState(State::Playing),
	myActiveMineField(NULL)
{
	// Temp
	myActiveMineField = new MineField(MineField::Size::Hard);
	Subscribe(Message::Type::GAME_OVER);
	Subscribe(Message::Type::KEY_ESCAPE_RELEASED);
}

Game::~Game()
{
	RemoveAllSubscriptions();
	Platy::Core::Util::SafeDelete(myActiveMineField);
}

void Game::Update(const float& deltaTime)
{
}

void Game::ReceiveMessage(const Message::Type& aMessageType)
{
	switch (aMessageType)
	{
	case Message::Type::GAME_OVER:
		break;
	case Message::Type::KEY_ESCAPE_RELEASED:
		Platy::Core::Util::SafeDelete(myActiveMineField);
		myActiveMineField = new MineField(MineField::Size::Hard); // TODO: Change difficulty to variable
		break;
	}
}

void Game::ReceiveMessage(const Message& aMessage, const Message::Type& aMessageType)
{
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;

	switch (myState)
	{
	case Game::State::GameOver:
		break;
	case Game::State::Menu:
		break;
	case Game::State::Playing:
		target.draw(*myActiveMineField);
		break;
	case Game::State::Paused:
		break;
	}
}
