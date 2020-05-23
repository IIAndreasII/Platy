#ifndef ASSETCONTAINER_H
#define ASSETCONTAINER_H

#include <vector>
#include "Spritesheet.h"
#include "SFML/Graphics/Font.hpp"

typedef SpriteSheet* SpriteSheetPtr;
typedef sf::Font* FontPtr;

class AssetContainer
{
public:
	~AssetContainer();

	static void Init();

	static const TexturePtr GetTexturePtr(const unsigned index);
	static const SpriteSheetPtr GetSpritesheetPtr(const unsigned index);
	static const FontPtr GetFontPtr(const unsigned index);

private:
	AssetContainer();

	static void LoadTextures();
	static void LoadAndParseSpriteSheets();
	static void LoadFonts();

	static std::vector<TexturePtr> myTexturePtrs;
	static std::vector<SpriteSheetPtr> mySpriteSheetPtrs;
	static std::vector<FontPtr> myFontPtrs;

};

#endif
