#ifndef ASSET_CONTAINER_H
#define ASSET_CONTAINER_H

#include <vector>
#include <Graphics/Spritesheet.h>
#include <SFML/Graphics/Font.hpp>

namespace Platy
{
	namespace Game
	{
		typedef Graphics::SpriteSheet* SpriteSheetPtr;

		class AssetContainer
		{
		public:
			AssetContainer() = delete;
			~AssetContainer();

			static void Init();

			static sf::Texture* GetTexturePtr(std::string name);
			static SpriteSheetPtr GetSpriteSheetPtr(std::string name);
			static sf::Font* GetFontPtr(std::string name);

		private:

			static void LoadTextures();
			static void LoadAndParseSpriteSheets();
			static void LoadFonts();

			static std::vector<sf::Texture*> myTexturePointers;
			static std::vector<SpriteSheetPtr> mySpriteSheetPointers;
			static std::vector<sf::Font*> myFontPointers;

			static std::vector<std::string> myTextureNames;
			static std::vector<std::string> mySpriteSheetNames;
			static std::vector<std::string> myFontNames;

			static const std::string& TrimFileName(std::string& path);
		};
	}
}
#endif
