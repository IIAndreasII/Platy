#ifndef TC_H
#define TC_H

#include <vector>
#include "Spritesheet.h"

typedef SpriteSheet* SpriteSheetPtr;

class AssetContainer
{
public:
	~AssetContainer();

	static void Init();

	static const TexturePtr GetTexturePtr(const unsigned index);
	static const SpriteSheetPtr GetSpritesheetPtr(const unsigned index);

private:
	AssetContainer();

	static void LoadTextures();
	static void LoadAndParseSpriteSheets();

	static std::vector<TexturePtr> myTexturePtrs;
	static std::vector<SpriteSheetPtr> mySpriteSheetPtrs;


};

#endif
