#include "Game.h"
#include "Scene.h"
#include "Message.h"
#include "Enums.h"

Game::Game(sf::RenderWindow& aRenderWindow) :
	myWindow(aRenderWindow),
	myPauseFlag(false)
{
}

Game::~Game()
{
	// TODO: Safely delete all pointers

}

void Game::Update(const float& deltaTime)
{
	// TODO: Update managers and stuff
	if (!myPauseFlag) 
	{
		// Update stuff here

		//myCurrentScene->Update(deltaTime);

	}
}

void Game::Draw(sf::RenderWindow &aWindow)
{
	//myCurrentScene->Draw(aWindow);
}

void Game::ReceiveMessage(const EMessageType& aMessageType)
{
	switch (aMessageType) {
		case EMessageType::TOGGLE_PAUSE:
			TogglePause();
			break;
		default:
			break;
	}
}

void Game::TogglePause()
{
	myPauseFlag = !myPauseFlag;
}

void Game::Pause()
{
	myPauseFlag = true;
}
