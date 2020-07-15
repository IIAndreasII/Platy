#include "Animator.h"
#include "SFML/Graphics/RenderTarget.hpp"

Animator::Animator(const SpriteSheet& aSpritesheet, const float aScale, const bool shouldLoop) :
	mySpriteSheet(aSpritesheet),
	mySprite(*mySpriteSheet.GetTexturePtr()),
	myIsPlaying(true),
	myIsLooping(shouldLoop),
	myCurrentFrame(0),
	myScale(aScale)
{
	mySprite.setScale(myScale, myScale);
	mySprite.setOrigin(mySpriteSheet.GetFrameWidth() / 2, mySpriteSheet.GetFrameHeight() / 2);
}

Animator::~Animator()
{
}


void Animator::Update(const float& deltaTime, const sf::Vector2f& aPosition)
{
	mySprite.setPosition(aPosition);
	if (mySpriteSheet.GetFrameCount() > 1 && myIsPlaying)
	{
		myCurrentFrame += mySpriteSheet.GetFrameRate() * deltaTime;
		if (myCurrentFrame >= mySpriteSheet.GetFrameCount())
		{
			if (!myIsLooping)
			{
				myIsPlaying = false;
				myCurrentFrame = mySpriteSheet.GetFrameCount() - 1;
			}
			else
			{
				myCurrentFrame = 0;
			}
		}

		sf::IntRect tempIntRect(
			mySpriteSheet.GetFrameWidth() * static_cast<int>(myCurrentFrame),
			0,
			mySpriteSheet.GetFrameWidth(),
			mySpriteSheet.GetFrameHeight());

		mySprite.setTextureRect(tempIntRect);
	}
}

void Animator::SetAnim(const SpriteSheet& aSpritesheet)
{
	mySpriteSheet = aSpritesheet;
	mySprite.setTexture(*mySpriteSheet.GetTexturePtr());
	myCurrentFrame = 0;
}

void Animator::Flip()
{
	mySprite.setScale(myScale * -1, myScale);
}

void Animator::SetFacingDirection(const int aDir)
{
	mySprite.setScale(aDir * myScale, myScale);
}

void Animator::TogglePlaying()
{
	myIsPlaying = !myIsPlaying;
}

void Animator::ToggleLooping()
{
	myIsLooping = !myIsLooping;
}

const sf::Sprite& Animator::GetCurrentFrame() const
{
	return mySprite;
}

void Animator::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mySprite);
}
