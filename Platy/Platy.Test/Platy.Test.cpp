#include <SFML/Graphics.hpp>

#include "Postmaster/PostMaster.h"

#include "Log.h"
#include "Containers/AssetContainer.h"
#include "Events/KeyboardEventHandler.h"
#include "Events/MouseEventHandler.h"
#include "Graphics/ParticleTest.h"
#include "Managers/ParticleManager.h"
#include "CoreTests/TestObservable.h"
#include "CoreTests/TestObserver.h"

#define TEST_CORE 1
#define TEST_GAME_CORE 0
#define TEST_LOG 0

int main()
{
#if TEST_LOG || TEST_GAME_CORE
	Platy::PlatyLog::Log::Init();
#endif
#if TEST_LOG
	Platy::PlatyLog::Log::Debug("Test msg");
	Platy::PlatyLog::Log::Warning("Test msg");
	Platy::PlatyLog::Log::Critical("Test msg");
	Platy::PlatyLog::Log::Critical(std::exception("Test exception"), "Test exception was thrown!");
	Platy::PlatyLog::Log::Information("Test msg");
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

	bool isWindowInFocus;

	/// Init clock for delta time
	sf::Clock tempClock;
	float deltaTime;
	// Init singletons
	Platy::PlatyLog::Log::Init();
	PostMaster::Init();
	AssetContainer::Init();
	ParticleManager::Init();

	ParticleTest tempParticleTest;

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

			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
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

		tempParticleTest.Update(deltaTime);

		//////////////////////////////////////////////////////////////////
	// Draw logic
		//////////////////////////////////////////////////////////////////
		window.clear();

		ParticleManager::EarlyDraw(window);


		ParticleManager::Draw(window);

		window.display();
		//////////////////////////////////////////////////////////////////
	}
#endif

	return 0;
}
