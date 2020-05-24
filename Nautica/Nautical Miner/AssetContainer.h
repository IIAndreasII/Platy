#ifndef ASSETCONTAINER_H
#define ASSETCONTAINER_H

#include <vector>
#include "Spritesheet.h"
#include "SFML/Graphics/Font.hpp"

typedef SpriteSheet* SpriteSheetPtr;

class AssetContainer
{
public:
	~AssetContainer();

	static void Init();

	static sf::Texture* GetTexturePtr(const std::string name);
	static SpriteSheetPtr GetSpritesheetPtr(const std::string name);
	static sf::Font* GetFontPtr(const std::string name);

private:
	AssetContainer();

	static void LoadTextures();
	static void LoadAndParseSpriteSheets();
	static void LoadFonts();

	static std::vector<sf::Texture*> myTexturePtrs;
	static std::vector<SpriteSheetPtr> mySpriteSheetPtrs;
	static std::vector<sf::Font*> myFontPtrs;

	static std::vector<std::string> myTextureNames;
	static std::vector<std::string> mySpriteSheetNames;
	static std::vector<std::string> myFontNames;

	static const std::string& TrimFileName(std::string& tempPath);

};

#endif
