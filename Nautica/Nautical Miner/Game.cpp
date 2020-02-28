#include "Game.h"



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
	}
}

void Game::Draw()
{
	// TODO: Draw stuff
}

void Game::TogglePause()
{
	myPauseFlag = !myPauseFlag;
}
