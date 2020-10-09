#include "Spritesheet.h"
#include "Util/Util.h"


////////////////////////////////////////
//
// Formatting sprite sheets in text file:
// filePath
// frameCount
// frameRate
// rows
// columns
//
////////////////////////////////////////


namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			SpriteSheet::SpriteSheet(
				sf::Texture* aTexturePtr,
				const int aFrameRate,
				const int aFrameCount,
				const int aRowCount,
				const int aColCount)
				:
				myTexturePtr(aTexturePtr),
				myFrameCount(aFrameCount),
				myFrameRate(aFrameRate),
				myFrameHeight(static_cast<int>(aTexturePtr->getSize().y) / aRowCount),
				myFrameWidth(static_cast<int>(aTexturePtr->getSize().x) / aColCount),
				myRows(aRowCount),
				myCols(aColCount)
			{
			}

			SpriteSheet::SpriteSheet(const SpriteSheet& other)
				:
				myTexturePtr(other.myTexturePtr),
				myFrameCount(other.myFrameCount),
				myFrameRate(other.myFrameRate),
				myFrameHeight(other.myFrameHeight),
				myFrameWidth(other.myFrameWidth),
				myRows(other.myRows),
				myCols(other.myCols)
			{
			}

			SpriteSheet::~SpriteSheet()
			{
				Core::Util::SafeDelete(myTexturePtr);
			}

			sf::IntRect SpriteSheet::GetFrameRect(const int& aFrameNbr) const
			{
				return {
					aFrameNbr % myCols * myFrameWidth,
					myFrameHeight * (aFrameNbr / myCols),
					myFrameWidth,
					myFrameHeight
				};
			}

			const sf::Texture* SpriteSheet::GetTexturePtr() const
			{
				return myTexturePtr;
			}

			const int& SpriteSheet::GetFrameCount() const
			{
				return myFrameCount;
			}

			const int& SpriteSheet::GetFrameRate() const
			{
				return myFrameRate;
			}

			const int& SpriteSheet::GetFrameHeight() const
			{
				return myFrameHeight;
			}

			const int& SpriteSheet::GetFrameWidth() const
			{
				return myFrameWidth;
			}

			const int& SpriteSheet::GetRows() const
			{
				return myRows;
			}

			const int& SpriteSheet::GetCols() const
			{
				return myCols;
			}
		}
	}
}
