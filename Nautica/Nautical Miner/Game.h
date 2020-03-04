#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include <vector>

class Scene;


class Game
{
public:

	Game(sf::RenderWindow& aRenderWindow);
	~Game();

	void Update(const float &deltaTime);
	void Draw();

	void TogglePause();

private:

	bool myPauseFlag;

	sf::RenderWindow& myWindow;

	std::vector<Scene*> myScenes;

};

#endif