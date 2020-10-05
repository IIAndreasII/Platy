#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "SFML/Graphics/Texture.hpp"

struct SpriteSheet
{
	SpriteSheet(sf::Texture* aTexturePtr, unsigned aFrameCount, unsigned aFrameRate = 1);
	~SpriteSheet();

	const sf::Texture* GetTexturePtr() const;
	const unsigned& GetFrameCount() const;
	const unsigned& GetFrameRate() const;
	const unsigned& GetFrameHeight() const;
	const unsigned& GetFrameWidth() const;

private:
	sf::Texture* myTexturePtr;
	unsigned myFrameCount;
	unsigned myFrameRate;
	unsigned myFrameHeight;
	unsigned myFrameWidth;
};

#endif
