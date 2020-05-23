#include "pch.h"
#include "Enum.h"

#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "AssetContainer.h"

#include "ParticleManager.h"
#include "ParticleEmitterFactory.h"
#include "ParticleEmitter.h"

#include <stdlib.h>
#include <crtdbg.h>
#include "Util.h"

// TODO:
// -Implement Scene model for different game states
// -Implement Timeline interface for i.e tutorials
// -Implement save file system (saving and loading gamestates). Do after gameplay and stuff is done

#if DEBUG
#include "Debug.h"
#define _CRTDBG_MAP_ALLOC
#endif

constexpr float FPS_WRITEOUT_INTERVAL = 1;

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
	ParticleManager::Init();

	// Init game (there should only be one game!)
	Game tempGame(window);

	// Init clock and delta time
	sf::Clock tempClock;
	float tempDeltaTime;


	// BEGIN Debug variables
#if DEBUG
	float fpsTimer = 0;

#endif
	// END Debug variables

#define TESTING 1

	// BEGIN Tests
#if TESTING
	float explosionTimer = 0;

	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	ParticleEmitter* pe = ParticleEmitterFactory::CreateFountain(12, mousePos, C_CYAN_DARK, 200, 250, 2, 270, 20, 2 * 9.82f);
	//ParticleEmitterFactory::CreateFountain(sf::Vector2f(150, 500), C_RÅSA, 1000, 150, 3, 270, 20, 9.82f);
	//ParticleEmitter& pe = *ParticleEmitterFactory::CreateShower(20, EOrientation::UP, sf::Vector2f(0, DEFAULT_WINDOW_HEIGHT), C_RÅSA, 1000, 200, 4.5f, DEFAULT_WINDOW_WIDTH, 70, 0);
	//ParticleEmitterFactory::CreateShower(4, EOrientation::DOWN, sf::Vector2f(220, 120), C_BLUE_DARK, 650, 200, 3, 960, 90, 2* 9.82f, false);
	//ParticleEmitterFactory::CreateCloud(20, sf::Vector2f(200, 100), C_WHITE, 5000, 25, 2, 1000);
#endif
	// END Tests

	// Main loop
	while (window.isOpen())
	{
		sf::Event tempEvent;
		while (window.pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed)
			{
				Debug::FinishSession();
				_CrtDumpMemoryLeaks();
				window.close();
			}
			else if (tempEvent.type == sf::Event::GainedFocus)
			{
				isWindowInFocus = true;
			}
			else if (tempEvent.type == sf::Event::LostFocus)
			{
				isWindowInFocus = false;
				tempGame.Pause();
			}
		}	

		// Get delta time
		tempDeltaTime = tempClock.restart().asSeconds();

#if DEBUG
		fpsTimer -= tempDeltaTime;
		if (fpsTimer <= 0)
		{
			fpsTimer = FPS_WRITEOUT_INTERVAL;
			std::cout << "FPS: " << (int)(1 / tempDeltaTime + 1) << std::endl;
		}
#endif
		// Update the game
		tempGame.Update(tempDeltaTime);


		// BEGIN Tests
#if TESTING
		mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		pe->SetPosition(mousePos);
		explosionTimer -= tempDeltaTime;
		if (explosionTimer <= 0)
		{
			ParticleEmitterFactory::CreateExplosion(
				12,
				sf::Vector2f(Util::RandFloat(200, DEFAULT_WINDOW_WIDTH - 200), Util::RandFloat(200, DEFAULT_WINDOW_HEIGHT - 200)), 
				sf::Color(Util::RandFloat(1, 255), Util::RandFloat(1, 255), Util::RandFloat(1, 255)),
				1000, 
				250, 
				1.5f,
				9.82f);
			/*for (size_t i = 0; i < 3; i++)
			{
				ParticleEmitterFactory::CreateFountain(
					6,
					sf::Vector2f(Util::RandFloat(220, 1180), DEFAULT_WINDOW_HEIGHT),
					C_BLUE_DARK,
					10,
					150,
					1.5f,
					270,
					20,
					9.82f * 2,
					EParticleEmitterType::FOUNTAIN_BURST);
			}*/
			explosionTimer = .1;
		}

		ParticleManager::Update(tempDeltaTime);
#endif
		// END Tests


		// Draw the game
		window.clear();
		tempGame.Draw(window);

#if TESTING
		// BEGIN Tests

		ParticleManager::Draw(window);

		// END Tests
#endif

		window.display();
	}
	//Debug::FinishSession();
}
