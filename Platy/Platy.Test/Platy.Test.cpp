#define TEST_CORE 0
#define TEST_GAME_CORE 1
#define TEST_LOG 0

#include <SFML/Graphics.hpp>

#include "Postmaster/PostMaster.h"

#include "Log.h"
#include "Containers/AssetContainer.h"
#include "Events/KeyboardEventHandler.h"
#include "Events/MouseEventHandler.h"
#include "Graphics/ParticleTest.h"
#include "CoreTests/TestObservable.h"
#include "CoreTests/TestObserver.h"
#include "Events/GamePadEventHandler.h"
#include "Graphics/Animator.h"
#include "Graphics/Managers/ParticleManager.h"


using namespace Platy::Game;
using namespace Graphics;

int main()
{
#if TEST_LOG || TEST_GAME_CORE
	Platy::Log::Init();
#endif

#if TEST_LOG
	Platy::Log::Debug("Test msg");
	Platy::Log::Warning("Test msg");
	Platy::Log::Critical("Test msg");
	Platy::Log::Critical(std::exception("Test exception"), "Test exception was thrown!");
	Platy::Log::Information("Test msg");
#endif


#if TEST_CORE

	TestObserver observer;

	TestObservable observable(&observer, 5);
	observable.UpdateData(10);

	auto* observerPtr = new TestObserver();

	TestObservable observable2(observerPtr, 5);
	observable2.UpdateData(10);

	delete observerPtr;
	observerPtr = nullptr;

#endif

#if TEST_GAME_CORE
	srand(static_cast<unsigned>(time(nullptr)));

	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Platy testing grounds");
	window.setVerticalSyncEnabled(false);
	window.setFramerateLimit(144);

	sf::Image icon;
	icon.loadFromFile("Assets/icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


	bool isWindowInFocus;

	/// Init clock for delta time
	sf::Clock tempClock;
	float deltaTime;
	// Init singletons
	Platy::Log::Init();
	PostMaster::Init();
	AssetContainer::Init();
	ParticleManager::Init();

	ParticleTest tempParticleTest;

	auto tempAnimator = Animator(*AssetContainer::GetSpriteSheetPtr("tailstest"), 1);
	auto tempAnimPos = sf::Vector2f(300, 300);
	tempAnimator.Flip();


	while (window.isOpen())
	{
		sf::Event tempEvent{};
		while (window.pollEvent(tempEvent))
		{
			switch (tempEvent.type)
			{
			case sf::Event::Closed:
				Platy::Log::Dispose();
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

			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
				MouseEventHandler::HandleEvent(tempEvent, window);
				break;
			case sf::Event::JoystickButtonPressed:
			case sf::Event::JoystickButtonReleased:
			case sf::Event::JoystickMoved:
			case sf::Event::JoystickConnected:
			case sf::Event::JoystickDisconnected:
				GamePadEventHandler::HandleEvent(tempEvent);
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

		tempParticleTest.Update(deltaTime);
		tempAnimator.Update(deltaTime, tempAnimPos);
		//////////////////////////////////////////////////////////////////
		// Draw logic
		//////////////////////////////////////////////////////////////////
		window.clear();

		ParticleManager::EarlyDraw(window);

		window.draw(tempAnimator);

		ParticleManager::Draw(window);

		window.display();
		//////////////////////////////////////////////////////////////////
	}
#endif

	return 0;
}
