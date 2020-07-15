#include "..\pch.h"
#include "..\Util\Enum.h"

#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "..\Containers\AssetContainer.h"

#include "..\Postmaster\PostMaster.h"

#include "..\Managers\ParticleManager.h"
#include "..\Factories\ParticleEmitterFactory.h"
#include "..\Graphics\ParticleEmitter.h"

#include "..\Events\KeyboardEventHandler.h"
#include "..\Events\MouseEventHandler.h"

#include <stdlib.h>
#include <crtdbg.h>
#include "..\Util\Util.h"

#include "..\Graphics\Animator.h"


#if DEBUG
#include "..\Util\Debug.h"
#define _CRTDBG_MAP_ALLOC
#endif

#include "..\UI\UIButton.cpp"

constexpr float FPS_WRITEOUT_INTERVAL = 1;


// TODO:
// -Implement Scene model for different game states
// -Implement Timeline interface for i.e tutorials
// -Implement save file system (saving and loading gamestates). Do after gameplay and stuff is done

int main()
{
	// Subnautical Whimsy Incorporated Mining
	std::string tempGameName = "S.W.I.M.";

	// Init focus tracker
	bool isWindowInFocus = true;

	// Init RNG
#if DEBUG
	srand(RNG_SEED);
#else
	srand((time(NULL)));
#endif
	// Configure window
	sf::RenderWindow window(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), tempGameName);
	window.setVerticalSyncEnabled(VSYNC);
	window.setFramerateLimit(DEFAULT_FRAMERATE);

	// Init debug
	Debug::Init();

	// Init containers
	AssetContainer::Init();

	// Init managers
	PostMaster::Init();
	ParticleManager::Init();

	// Init game (there should only be one game!)
	Game* tempGame = new Game(window);

	// Init clock and delta time
	sf::Clock tempClock;
	float tempDeltaTime;


	// BEGIN Debug variables
#if DEBUG
	float fpsTimer = 0;
	sf::Text fpsText("", *AssetContainer::GetFontPtr("firstorder"));
	fpsText.setPosition(5, 0);
#endif
	// END Debug variables

	// Main loop
	while (window.isOpen())
	{
		sf::Event tempEvent;
		while (window.pollEvent(tempEvent))
		{
			switch (tempEvent.type)
			{
			case sf::Event::Closed:
#if DEBUG
				Debug::FinishSession();
				_CrtDumpMemoryLeaks();
#endif
				window.close();
				break;

			case sf::Event::GainedFocus:
				isWindowInFocus = true;
				break;
			
			case sf::Event::LostFocus:
				isWindowInFocus = false;
				tempGame->Pause();
				break;
			
			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				KeyboardEventHandler::HandleEvent(tempEvent);
				break;
			
			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
			case sf::Event::MouseMoved:
				MouseEventHandler::HandleEvent(tempEvent, window);
				break;
			}
		}	

		// Get delta time
		tempDeltaTime = tempClock.restart().asSeconds();

#if DEBUG
		fpsTimer -= tempDeltaTime;
		if (fpsTimer <= 0)
		{
			fpsTimer = FPS_WRITEOUT_INTERVAL;
			fpsText.setString("FPS: " + std::to_string((int)(1 / tempDeltaTime + 1)));
		}
#endif
		ParticleManager::Update(tempDeltaTime);
		// Update the game
		tempGame->Update(tempDeltaTime);

		// Draw the game
		window.clear();
		tempGame->Draw(window);


		window.draw(fpsText);
		window.display();
	}
}
