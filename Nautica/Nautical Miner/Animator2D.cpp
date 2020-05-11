#include "Animator2D.h"
#include "SFML/Graphics/RenderTarget.hpp"

Animator2D::Animator2D(const SpriteSheet& aSpritesheet, const bool shouldLoop) :
	mySpriteSheet(aSpritesheet),
	mySprite(*mySpriteSheet.GetTexturePtr()),
	myIsPlaying(true),
	myIsLooping(shouldLoop),
	myCurrentFrame(0)
{
}

Animator2D::~Animator2D()
{
}


void Animator2D::Update(const float& deltaTime, const sf::Vector2f& aPosition)
{
	mySprite.setPosition(aPosition);
	if (mySpriteSheet.GetFrameCount() > 1 && myIsPlaying)
	{
		myCurrentFrame += mySpriteSheet.GetFrameRate() * deltaTime;
		if (myCurrentFrame >= mySpriteSheet.GetFrameCount())
		{
			myCurrentFrame = 0;
			if (!myIsLooping)
			{
				myIsPlaying = false;
			}
		}

		sf::IntRect tempIntRect(
			mySpriteSheet.GetFrameWidth() * static_cast<int>(myCurrentFrame),
			0,
			mySpriteSheet.GetFrameWidth() / mySpriteSheet.GetFrameCount(),
			mySpriteSheet.GetFrameHeight());

		mySprite.setTextureRect(tempIntRect);
	}
}

void Animator2D::SetAnim(const SpriteSheet& aSpritesheet)
{
	mySpriteSheet = aSpritesheet;
	mySprite.setTexture(*mySpriteSheet.GetTexturePtr());
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

const sf::Sprite& Animator2D::GetCurrentFrame() const
{
	return mySprite;
}

void Animator2D::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mySprite);
}
