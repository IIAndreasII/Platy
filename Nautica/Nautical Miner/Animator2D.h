#ifndef ANIMATOR2D
#define ANIMATOR2D

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "SFML/System/Vector2.hpp"

typedef sf::Texture* TexturePtr;

class Animator2D
{
public:

	Animator2D();
	Animator2D(TexturePtr aTexturePtr, const unsigned frameCount, const unsigned frameRate);
	~Animator2D();
	
	void Update(const float& deltaTime, const sf::Vector2f& aPosition);

	void SetAnim(TexturePtr aTexturePtr, const unsigned aFrameCount, const unsigned frameRate);

	void TogglePlaying();
	void ToggleLooping();

	const sf::Sprite& GetCurrentFrame();

private:

	TexturePtr mySpriteSheet;
	sf::Sprite mySprite;

	bool myIsPlaying;
	bool myIsLooping;

	unsigned myFrameCount;
	unsigned myFrameRate;

	float myCurrentFrame;

};

#endif