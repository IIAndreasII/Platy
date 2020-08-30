#include "pch.h"
#include "Game.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Postmaster/Message.h"
#include "Platy.Game.Core/Managers/ParticleManager.h"
#include "Platy.Game.Core/Containers/AssetContainer.h"

Game::Game() :
	myState(State::Playing),
	myChosenDifficulty(MineField::Size::Hard),
	myActiveMineField(NULL),
	myMineCounterText("", *AssetContainer::GetFontPtr("digital_characters")),
	myTimeCounterText("", *AssetContainer::GetFontPtr("digital_characters"))
{
	myMineCounterText.setFillColor(sf::Color(255, 0, 0));
	myMineCounterText.setCharacterSize(50);
	myMineCounterText.setPosition(200, 0);

	myTimeCounterText.setFillColor(sf::Color(255, 0, 0));
	myTimeCounterText.setCharacterSize(50);
	myTimeCounterText.setPosition(500, 0);

	ResetMineField();
	UpdateMineCounterText();
	UpdateTimeCounterText();

	Subscribe(Message::Type::GAME_OVER);
	Subscribe(Message::Type::VICTORY);
	Subscribe(Message::Type::KEY_ESCAPE_RELEASED);
	Subscribe(Message::Type::TILE_FLAGGED);
	Subscribe(Message::Type::TILE_UNFLAGGED);
}

Game::~Game()
{
	RemoveAllSubscriptions();
	Platy::Core::Util::SafeDelete(myActiveMineField);
}

void Game::Update(const float& deltaTime)
{
	myActiveMineField->Update(deltaTime);
	UpdateTimeCounterText();
}

void Game::ReceiveMessage(const Message::Type& aMessageType)
{
	switch (aMessageType)
	{
	case Message::Type::GAME_OVER:
		break;
	case Message::Type::KEY_ESCAPE_RELEASED:
		ResetMineField();
		break;
	case Message::Type::TILE_FLAGGED:
	case Message::Type::TILE_UNFLAGGED:
		UpdateMineCounterText();
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
		target.draw(myMineCounterText);
		target.draw(myTimeCounterText);
	case Game::State::Paused:
		break;
	}
}

void Game::ResetMineField()
{
	Platy::Core::Util::SafeDelete(myActiveMineField);
	ParticleManager::RemoveAllEffects();
	
	sf::Vector2i offset;
	switch (myChosenDifficulty)
	{
	case MineField::Size::Easy:
		offset = sf::Vector2i(
			DEFAULT_WINDOW_WIDTH  / 2 - (int)((float)COLS_EASY / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - (int)((float)ROWS_EASY / 2) * 32);
		break;
	case MineField::Size::Intermediate:
		offset = sf::Vector2i(
			DEFAULT_WINDOW_WIDTH / 2 - (int)((float)COLS_INTERMEDIATE / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - (int)((float)ROWS_INTERMEDIATE / 2) * 32);
		break;
	case MineField::Size::Hard:
		offset = sf::Vector2i(
			DEFAULT_WINDOW_WIDTH / 2 - (int)((float)COLS_HARD / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - (int)((float)ROWS_HARD / 2) * 32);
		break;
	}

	myActiveMineField = new MineField(myChosenDifficulty, offset);
}

void Game::UpdateMineCounterText()
{
	std::string text = myActiveMineField->GetNbrMinesLeft() > 9 ?
		"0" + std::to_string(myActiveMineField->GetNbrMinesLeft())
		: "00" + std::to_string(myActiveMineField->GetNbrMinesLeft());
	myMineCounterText.setString(text);
}

void Game::UpdateTimeCounterText()
{
	std::string text = "000";
	if (myActiveMineField->GetElapsedSeconds() < 10 && myActiveMineField->GetElapsedSeconds() > 0)
	{
		text = "00" + std::to_string(myActiveMineField->GetElapsedSeconds());
	}
	else if (myActiveMineField->GetElapsedSeconds() < 100 && myActiveMineField->GetElapsedSeconds() > 9)
	{
		text = "0" + std::to_string(myActiveMineField->GetElapsedSeconds());
	}
	else if (myActiveMineField->GetElapsedSeconds() > 99)
	{
		text = std::to_string(myActiveMineField->GetElapsedSeconds());
	}
	myTimeCounterText.setString(text);
}
