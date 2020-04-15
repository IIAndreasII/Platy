#include "pch.h"

#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "ParticleFactory.h"

#include "ParticleManager.h"

#include "ParticleFountain.h"
#include "ParticleEmitterFactory.h"
#include "Util.h"

#include <iostream>
#include <future>


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
#ifdef DEBUG
	srand(RNG_SEED);
#else
	srand((time(NULL)));
#endif
	// Configure window
	sf::RenderWindow window(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), tempGameName);
	window.setVerticalSyncEnabled(VSYNC);

	// Init factories
	ParticleFactory::Init();

	// Init managers
	ParticleManager::Init();

	// Init game (there should only be one game!)
	Game tempGame(window);

	// Init clock and delta time
	sf::Clock tempClock;
	float tempDeltaTime;


	// BEGIN Tests
	
	float explosionTimer = 0;

	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	ParticleEmitterFactory::CreateFountain(&mousePos, sf::Color(0, 100, 100), 270, 20, 200, 50, 8, 9.82f);
	//ParticleEmitterFactory::CreateExplosion(sf::Vector2f(250, 250), sf::Color(255, 0, 100), 200, 4, 250, 0, 2.5f);
	//ParticleEmitterFactory::CreateShower(EOrientation::VERTICAL, sf::Vector2f(0, 0), sf::Color(100, 100, 255), DEFAULT_WINDOW_HEIGHT, 1500, 500, .75f, 5, G);
	//ParticleEmitterFactory::CreateShower(EOrientation::VERTICAL_INVERTED, sf::Vector2f(800, 300), sf::Color(255, 255, 255), 200, 500, 500, 5, 5, G);

	// END Tests

	// Main loop
	while (window.isOpen())
	{
		sf::Event tempEvent;
		while (window.pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed)
			{
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

		// Update game only if window is in focus
		if (isWindowInFocus)
		{
			// Get delta time
			tempDeltaTime = tempClock.restart().asSeconds();
#ifdef DEBUG
			//std::cout << "FPS: " + std::to_string(1 / tempDeltaTime) << std::endl;
#endif
			// Update the game
			tempGame.Update(tempDeltaTime);


			// BEGIN Tests

			mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
			ParticleManager::Update(tempDeltaTime);

			explosionTimer -= tempDeltaTime;
			if (explosionTimer <= 0)
			{
				ParticleEmitterFactory::CreateExplosion(sf::Vector2f(Util::RandFloat(200, 600), Util::RandFloat(200, 800)), sf::Color(Util::RandFloat(1, 255), Util::RandFloat(1, 255), Util::RandFloat(1, 255)), 200, 6, 250, 0, 2.5f);
				explosionTimer = .5;
			}

			// END Tests


			// Draw the game
			window.clear();
			tempGame.Draw(window);


			// BEGIN Tests

			ParticleManager::Draw(window);

			// END Tests


			window.display();
		}
	}
}
