#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "Subscriber.h"

class Scene;

typedef Scene* ScenePtr;

class Game : Subscriber
{
public:

	Game(sf::RenderWindow& aRenderWindow);
	~Game();

	void Update(const float &deltaTime);
	void Draw();

	void ReceiveMessage(const EMessageType& aMessageType) override;

	void TogglePause();
	void Pause();

private:

	bool myPauseFlag;

	sf::RenderWindow& myWindow;

	std::vector<ScenePtr> myScenes;

	ScenePtr myCurrentScene;

};

#endif