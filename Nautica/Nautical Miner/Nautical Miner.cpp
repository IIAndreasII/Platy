#include "pch.h"

#include "Game.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>


#include <iostream>


// TODO:
// -Implement GrowingArray
// -Implement TextureContainer
// -Implement Scene model for different game states
// -Implement Timeline interface for i.e tutorials
// -Implement save file system (saving and loading gamestates). Do after gameplay and stuff is done


int main()
{
	// Subnautical Well Incorporated Mining
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

	// Init game (there should only be one game!)
	Game tempGame(window);

	// Init clock and delta time
	sf::Clock tempClock;
	float tempDeltaTime;

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
			}
		}


		// Update game only if window is in focus
		if (true)//isWindowInFocus)
		{
			// Get delta time
			tempDeltaTime = tempClock.restart().asSeconds();
#ifdef DEBUG
			std::cout << "FPS: " + std::to_string(1 / tempDeltaTime) << std::endl;
#endif
			// Update the game
			tempGame.Update(tempDeltaTime);

			// Draw the game
			window.clear();
			tempGame.Draw();
			window.display();
		}
	}
}
