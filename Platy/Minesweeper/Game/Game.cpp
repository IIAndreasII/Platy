#include "Game.h"

Game::Game()
	:
	myState(State::Menu)
{
}

Game::~Game()
{
}

void Game::Update(const float& deltaTime)
{
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = NULL;

	// TODO: Draw stuff
}
