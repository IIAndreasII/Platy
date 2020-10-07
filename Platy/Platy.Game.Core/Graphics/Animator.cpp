#include "Animator.h"
#include "SFML/Graphics/RenderTarget.hpp"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			Animator::Animator(const SpriteSheet& aSpriteSheet, const float aScale, const bool shouldLoop) :
				mySpriteSheet(aSpriteSheet),
				mySprite(*mySpriteSheet.GetTexturePtr()),
				myIsPlaying(true),
				myIsLooping(shouldLoop),
				myCurrentFrame(0),
				myScale(aScale)
			{
				mySprite.setScale(myScale, myScale);
				mySprite.setOrigin(static_cast<float>(mySpriteSheet.GetFrameWidth()) / 2,
				                   static_cast<float>(mySpriteSheet.GetFrameHeight()) / 2);
			}

			Animator::~Animator() = default;


			void Animator::Update(const float& someDeltaTime, const sf::Vector2f& aPosition)
			{
				mySprite.setPosition(aPosition);
				if (mySpriteSheet.GetFrameCount() > 1 && myIsPlaying)
				{
					myCurrentFrame += static_cast<float>(mySpriteSheet.GetFrameRate()) * someDeltaTime;
					if (myCurrentFrame >= static_cast<float>(mySpriteSheet.GetFrameCount()))
					{
						if (!myIsLooping)
						{
							myIsPlaying = false;
							myCurrentFrame = static_cast<float>(mySpriteSheet.GetFrameCount() - 1);
						}
						else
						{
							myCurrentFrame = 0;
						}
					}

					const sf::IntRect tempIntRect(
						mySpriteSheet.GetFrameWidth() * static_cast<int>(myCurrentFrame),
						0,
						mySpriteSheet.GetFrameWidth(),
						mySpriteSheet.GetFrameHeight());

					mySprite.setTextureRect(tempIntRect);
				}
			}

			void Animator::SetAnim(const SpriteSheet& aSpriteSheet)
			{
				mySpriteSheet = aSpriteSheet;
				mySprite.setTexture(*mySpriteSheet.GetTexturePtr());
				myCurrentFrame = 0;
			}

			void Animator::Flip()
			{
				mySprite.setScale(myScale * -1, myScale);
			}

			void Animator::SetFacingDirection(const int aDir)
			{
				mySprite.setScale(static_cast<float>(aDir) * myScale, myScale);
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
		}
	}
}
