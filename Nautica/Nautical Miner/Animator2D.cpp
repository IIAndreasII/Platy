#include "Animator2D.h"

Animator2D::Animator2D()
{
}

Animator2D::Animator2D(TexturePtr aTexturePtr, const unsigned aFrameCount, const unsigned aFrameRate) :
	mySpriteSheet(aTexturePtr),
	myFrameCount(aFrameCount),
	myFrameRate(aFrameRate),
	mySprite(*mySpriteSheet),
	myIsPlaying(true),
	myIsLooping(true),
	myCurrentFrame(0)
{
}

Animator2D::~Animator2D()
{
	mySpriteSheet = nullptr;
}


void Animator2D::Update(const float& deltaTime, const sf::Vector2f& aPosition)
{
	if (myIsPlaying)
	{
		mySprite.setPosition(aPosition);
		myCurrentFrame += myFrameRate * deltaTime;
		
		if (myCurrentFrame >= myFrameCount)
		{
			myCurrentFrame = 0;
		}

		sf::IntRect tempIntRect(mySpriteSheet->getSize().x / myFrameCount * static_cast<int>(myCurrentFrame),
								0,
								mySpriteSheet->getSize().x / myFrameCount,
								mySpriteSheet->getSize().y);

		mySprite.setTextureRect(tempIntRect);
	}
}

void Animator2D::SetAnim(TexturePtr aTexturePtr, const unsigned aFrameCount, const unsigned aFrameRate)
{
	mySpriteSheet = aTexturePtr;
	mySprite.setTexture(*mySpriteSheet);
	myFrameCount = aFrameCount;
	myFrameRate = aFrameRate;
	myCurrentFrame = 0;
}

void Animator2D::TogglePlaying()
{
	myIsPlaying = !myIsPlaying;
}

void Animator2D::ToggleLooping()
{
	myIsLooping = !myIsLooping;
}

const sf::Sprite& Animator2D::GetCurrentFrame()
{
	return mySprite;
}
