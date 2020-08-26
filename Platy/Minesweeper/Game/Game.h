#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics/Drawable.hpp"

class Game : public sf::Drawable
{
public:
	Game();
	~Game();

	enum class State
	{
		Menu,
		Playing,
		Paused
	};

	void Update(const float& deltaTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	State myState;

};

#endif