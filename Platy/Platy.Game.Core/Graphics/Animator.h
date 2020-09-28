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

	Animator(const SpriteSheet& aSpriteSheet, float aScale = DEFAULT_ANIM_SCALE, bool shouldLoop = true);
	~Animator() override;

	void Update(const float& deltaTime, const sf::Vector2f& aPosition);

	void SetAnim(const SpriteSheet& aSpriteSheet);

	void Flip();
	void SetFacingDirection(int aDir);
	void TogglePlaying();
	void ToggleLooping();

	const sf::Sprite& GetCurrentFrame() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	SpriteSheet mySpriteSheet;
	sf::Sprite mySprite;

	bool myIsPlaying;
	bool myIsLooping;

	float myCurrentFrame;
	float myScale;
};

#endif
