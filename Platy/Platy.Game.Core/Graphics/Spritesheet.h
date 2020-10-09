#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "SFML/Graphics/Texture.hpp"

namespace Platy
{
	namespace Game
	{
		namespace Graphics
		{
			struct SpriteSheet
			{
				SpriteSheet(
					sf::Texture* aTexturePtr,
					int aFrameRate,
					int aFrameCount,
					int aRowCount,
					int aColCount);

				SpriteSheet(const SpriteSheet& other);
				~SpriteSheet();

				sf::IntRect GetFrameRect(const int& aFrameNbr) const;

				const sf::Texture* GetTexturePtr() const;
				const int& GetFrameCount() const;
				const int& GetFrameRate() const;
				const int& GetFrameHeight() const;
				const int& GetFrameWidth() const;

				const int& GetRows() const;
				const int& GetCols() const;

			private:
				sf::Texture* myTexturePtr;
				int myFrameCount;
				int myFrameRate;
				int myFrameHeight;
				int myFrameWidth;

				int myRows;
				int myCols;
			};
		}
	}
}
#endif
