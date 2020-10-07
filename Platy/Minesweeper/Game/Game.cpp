#include "Game.h"
#include "pch.h"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


#include "Graphics/Managers/ParticleManager.h"
#include "Platy.Core/Util/Util.h"
#include "Platy.Game.Core/Containers/AssetContainer.h"
#include "Platy.Game.Core/Postmaster/Message.h"

using namespace Platy::Game;
using namespace Graphics;

Game::Game() :
	myState(EState::Playing),
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

	Subscribe(Message::EType::GAME_OVER);
	Subscribe(Message::EType::VICTORY);
	Subscribe(Message::EType::KEY_ESCAPE_RELEASED);
	Subscribe(Message::EType::TILE_FLAGGED);
	Subscribe(Message::EType::TILE_UN_FLAGGED);
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

void Game::ReceiveMessage(const Message::EType& aMessageType)
{
	switch (aMessageType)
	{
	case Message::EType::GAME_OVER:
		break;
	case Message::EType::KEY_ESCAPE_RELEASED:
		ResetMineField();
		break;
	case Message::EType::TILE_FLAGGED:
	case Message::EType::TILE_UN_FLAGGED:
		UpdateMineCounterText();
		break;
	default:
		break;
	}
}

void Game::ReceiveMessage(const Message& aMessage, const Message::EType& aMessageType)
{
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = nullptr;
	switch (myState)
	{
	case EState::GameOver:
	case EState::Paused:
	case EState::Menu:
		break;
	case EState::Playing:
		target.draw(*myActiveMineField);
		target.draw(myMineCounterText);
		target.draw(myTimeCounterText);
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
			DEFAULT_WINDOW_WIDTH / 2 - static_cast<int>(static_cast<float>(COLS_EASY) / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - static_cast<int>(static_cast<float>(ROWS_EASY) / 2) * 32);
		break;
	case MineField::Size::Intermediate:
		offset = sf::Vector2i(
			DEFAULT_WINDOW_WIDTH / 2 - static_cast<int>(static_cast<float>(COLS_INTERMEDIATE) / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - static_cast<int>(static_cast<float>(ROWS_INTERMEDIATE) / 2) * 32);
		break;
	case MineField::Size::Hard:
		offset = sf::Vector2i(
			DEFAULT_WINDOW_WIDTH / 2 - static_cast<int>(static_cast<float>(COLS_HARD) / 2) * 32,
			DEFAULT_WINDOW_HEIGHT / 2 - static_cast<int>(static_cast<float>(ROWS_HARD) / 2) * 32);
		break;
	}

	myActiveMineField = new MineField(myChosenDifficulty, offset);

	UpdateMineCounterText();
}

void Game::UpdateMineCounterText()
{
	const std::string text = myActiveMineField->GetNbrMinesLeft() > 9
		                         ? "0" + std::to_string(myActiveMineField->GetNbrMinesLeft())
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
