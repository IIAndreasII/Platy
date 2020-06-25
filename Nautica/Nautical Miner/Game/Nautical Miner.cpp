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

#define TESTING 1

	// BEGIN Tests
#if TESTING
	
	UIButton<Game> testBtn("Test", &Game::TestFunc, tempGame, sf::Vector2f(200, 200));



	sf::Font testFont = *AssetContainer::GetFontPtr("firstorder");
	sf::Texture testTexture = *AssetContainer::GetTexturePtr("Zweihander");
	SpriteSheetPtr testSS = AssetContainer::GetSpritesheetPtr("Chest Full");




	Animator testAnim = Animator(*testSS);
	//testAnim.Flip();
	sf::Sprite testSprite(testTexture);
	testSprite.setPosition(500, 300);
	testSprite.setScale(4, 4);

	float explosionTimer = 0;

	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	//ParticleEmitter* pe = ParticleEmitterFactory::CreateFountain(12, mousePos, C_CYAN_DARK, 200, 250, 2, 270, 20, true, 2 * 9.82f);
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
		// Update the game
		tempGame->Update(tempDeltaTime);


		// BEGIN Tests
#if TESTING

		mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
		testAnim.Update(tempDeltaTime, mousePos);
		//pe->SetPosition(mousePos);
		explosionTimer -= tempDeltaTime;
		if (explosionTimer <= 0)
		{
			/*ParticleEmitterFactory::CreateExplosion(
				12,
				sf::Vector2f(Util::RandFloat(200, DEFAULT_WINDOW_WIDTH - 200), Util::RandFloat(200, DEFAULT_WINDOW_HEIGHT - 200)), 
				sf::Color(Util::RandFloat(1, 255), Util::RandFloat(1, 255), Util::RandFloat(1, 255)),
				1000, 
				250, 
				1.5f,
				9.82f);*/
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
			explosionTimer = .1f;
		}

		ParticleManager::Update(tempDeltaTime);
#endif
		// END Tests


		// Draw the game
		window.clear();
		tempGame->Draw(window);

		// BEGIN Tests
#if TESTING

		ParticleManager::EarlyDraw(window);
		window.draw(testSprite);
		window.draw(testAnim);
		ParticleManager::Draw(window);

		window.draw(testBtn);

		window.draw(fpsText);
#endif
		// END Tests

		window.display();
	}
}
