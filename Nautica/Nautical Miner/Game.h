#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>

class Game
{
public:

	Game();
	Game(sf::RenderWindow& aRenderWindow);
	~Game();

	void Update(const float &deltaTime);
	void Draw();

	void TogglePause();

private:

	bool myPauseFlag;

	sf::RenderWindow& myWindow;

};

#endif