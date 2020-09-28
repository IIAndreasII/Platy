#include "pch.h"
#include "Game/Game.h"

#include <SFML/Graphics.hpp>

#include "Platy.Log/Log.h"
#include "Platy.Game.Core/Postmaster/PostMaster.h"
#include "Platy.Game.Core/Events/MouseEventHandler.h"
#include "Platy.Game.Core/Managers/ParticleManager.h"
#include "Platy.Game.Core/Containers/AssetContainer.h"
#include "Platy.Game.Core/Events/KeyboardEventHandler.h"

constexpr const char* GAME_NAME = "Minesweeper";


int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	sf::RenderWindow window;
	window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), GAME_NAME);
	window.setVerticalSyncEnabled(false);
	window.setFramerateLimit(TARGET_FRAME_RATE);

	bool isWindowInFocus;

	/// Init clock for delta time
	sf::Clock tempClock;
	float deltaTime;

	// Init singletons
	Platy::PlatyLog::Log::Init();

	PostMaster::Init();

	AssetContainer::Init();

	ParticleManager::Init();

	// Init game
	Game tempGame;


	while (window.isOpen())
	{
		sf::Event tempEvent{};
		while (window.pollEvent(tempEvent))
		{
			switch (tempEvent.type)
			{
			case sf::Event::Closed:
				Platy::PlatyLog::Log::Dispose();
				window.close();
				break;

			case sf::Event::GainedFocus:
				isWindowInFocus = true;
				break;

			case sf::Event::LostFocus:
				isWindowInFocus = false;
				break;

			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				KeyboardEventHandler::HandleEvent(tempEvent);
				break;

			case sf::Event::MouseWheelMoved:
			case sf::Event::MouseWheelScrolled:
			case sf::Event::MouseEntered:
			case sf::Event::MouseLeft:
			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
			case sf::Event::MouseMoved:
				MouseEventHandler::HandleEvent(tempEvent, window);
				break;
			default:
				break;
			}
		}

		deltaTime = tempClock.restart().asSeconds();

		//////////////////////////////////////////////////////////////////
		// Update logic
		//////////////////////////////////////////////////////////////////

		ParticleManager::Update(deltaTime);

		tempGame.Update(deltaTime);

		//////////////////////////////////////////////////////////////////
		// Draw logic
		//////////////////////////////////////////////////////////////////
		window.clear();

		ParticleManager::EarlyDraw(window);

		window.draw(tempGame);

		ParticleManager::Draw(window);

		window.display();
		//////////////////////////////////////////////////////////////////
	}
}
