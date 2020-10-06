#include "Spritesheet.h"
#include "Util/Util.h"

SpriteSheet::SpriteSheet(sf::Texture* aTexturePtr, const unsigned aFrameCount, const unsigned aFrameRate)
	:
	myTexturePtr(aTexturePtr),
	myFrameCount(aFrameCount),
	myFrameRate(aFrameRate),
	myFrameHeight(aTexturePtr->getSize().y),
	myFrameWidth(aTexturePtr->getSize().x / aFrameCount)
{
}

SpriteSheet::~SpriteSheet()
{
	Platy::Core::Util::SafeDelete(myTexturePtr);
}

const sf::Texture* SpriteSheet::GetTexturePtr() const
{
	return myTexturePtr;
}

const unsigned& SpriteSheet::GetFrameCount() const
{
	return myFrameCount;
}

const unsigned& SpriteSheet::GetFrameRate() const
{
	return myFrameRate;
}

const unsigned& SpriteSheet::GetFrameHeight() const
{
	return myFrameHeight;
}

const unsigned& SpriteSheet::GetFrameWidth() const
{
	return myFrameWidth;
}
