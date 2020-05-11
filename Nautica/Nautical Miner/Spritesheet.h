#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "SFML/Graphics/Texture.hpp"

typedef sf::Texture* TexturePtr;

struct SpriteSheet
{
public:
	SpriteSheet(TexturePtr aTexturePtr, const unsigned myFrameCount, const unsigned myFrameRate = 1);
	~SpriteSheet();

	const TexturePtr GetTexturePtr() const;
	const unsigned& GetFrameCount() const;
	const unsigned& GetFrameRate() const;
	const unsigned& GetFrameHeight() const;
	const unsigned& GetFrameWidth() const;

private:
	TexturePtr myTexturePtr;
	unsigned myFrameCount;
	unsigned myFrameRate;
	unsigned myFrameHeight;
	unsigned myFrameWidth;
};

#endif