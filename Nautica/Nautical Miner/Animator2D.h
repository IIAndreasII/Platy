#ifndef ANIMATOR2D
#define ANIMATOR2D

#include "Spritesheet.h"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Sprite.hpp>


class Animator2D
{
public:

	Animator2D(const SpriteSheet& aSpritesheet, const bool shouldLoop = true);
	~Animator2D();
	
	void Update(const float& deltaTime, const sf::Vector2f& aPosition);

	void SetAnim(const SpriteSheet& aSpritesheet);

	void TogglePlaying();
	void ToggleLooping();

	const sf::Sprite& GetCurrentFrame() const;

private:

	SpriteSheet mySpriteSheet;
	sf::Sprite mySprite;

	bool myIsPlaying;
	bool myIsLooping;
	
	float myCurrentFrame;
};

#endif