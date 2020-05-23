#include "pch.h"
#include "Spritesheet.h"

SpriteSheet::SpriteSheet(TexturePtr aTexturePtr, const unsigned aFrameCount, const unsigned aFrameRate)
	: myTexturePtr(aTexturePtr),
	myFrameCount(aFrameCount),
	myFrameRate(aFrameRate),
	myFrameWidth(aTexturePtr->getSize().x / aFrameCount),
	myFrameHeight(aTexturePtr->getSize().y)
{
}

SpriteSheet::~SpriteSheet()
{
	SafeDelete(myTexturePtr);
}

const TexturePtr SpriteSheet::GetTexturePtr() const
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
