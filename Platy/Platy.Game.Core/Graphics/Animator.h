#ifndef ANIMATOR2D
#define ANIMATOR2D

#include "Spritesheet.h"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics/Drawable.hpp"


constexpr float DEFAULT_ANIM_SCALE = 4;

class Animator : public sf::Drawable
{
public:

	Animator(const SpriteSheet& aSpritesheet, const float aScale = DEFAULT_ANIM_SCALE, const bool shouldLoop = true);
	~Animator();
	
	void Update(const float& deltaTime, const sf::Vector2f& aPosition);

	void SetAnim(const SpriteSheet& aSpritesheet);

	void Flip();
	void SetFacingDirection(const int aDir);
	void TogglePlaying();
	void ToggleLooping();

	const sf::Sprite& GetCurrentFrame() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	SpriteSheet mySpriteSheet;
	sf::Sprite mySprite;

	bool myIsPlaying;
	bool myIsLooping;
	
	float myCurrentFrame;
	float myScale;
};

#endif