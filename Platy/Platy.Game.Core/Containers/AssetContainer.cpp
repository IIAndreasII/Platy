#include "AssetContainer.h"

#include <fstream>

#include <Platy.Core/Util/Util.h>
#include <Platy.Log/Log.h>

using namespace Platy::Core;

namespace Platy
{
	namespace Game
	{
		constexpr const char* FILE_PATHS_FILE_FONTS = "Assets/File_paths_Fonts.txt";
		constexpr const char* FILEPATH_FONTS = "Assets/Fonts/";
		constexpr const char* FILE_PATHS_FILE_TEXTURES = "Assets/File_paths_Textures.txt";
		constexpr const char* FILEPATH_TEXTURES = "Assets/Textures/Sprites/";
		constexpr const char* FILE_PATHS_FILES_SPRITE_SHEETS = "Assets/File_paths_SpriteSheets.txt";
		constexpr const char* FILEPATH_SPRITE_SHEETS = "Assets/Textures/SpriteSheets/";

		std::vector<sf::Texture*> AssetContainer::myTexturePointers;
		std::vector<SpriteSheetPtr> AssetContainer::mySpriteSheetPointers;
		std::vector<sf::Font*> AssetContainer::myFontPointers;

		std::vector<std::string> AssetContainer::myTextureNames;
		std::vector<std::string> AssetContainer::mySpriteSheetNames;
		std::vector<std::string> AssetContainer::myFontNames;

		AssetContainer::~AssetContainer()
		{
			for (auto* it : myTexturePointers)
			{
				Util::SafeDelete(it);
			}
			for (auto* it : mySpriteSheetPointers)
			{
				Util::SafeDelete(it);
			}
			for (auto* it : myFontPointers)
			{
				Util::SafeDelete(it);
			}
		}

		void AssetContainer::Init()
		{
			LoadTextures();
			LoadAndParseSpriteSheets();
			LoadFonts();
		}

		sf::Font* AssetContainer::GetFontPtr(std::string name)
		{
			Util::ToLowerCase(name);
			const auto it = std::find(myFontNames.begin(), myFontNames.end(), name);
			if (it != myFontNames.end())
			{
				return myFontPointers.at(std::distance(myFontNames.begin(), it));
			}
			Log::Warning("AssetContainer::GetFontPtr(): Font with name \"" + name + "\" not found!");
			return nullptr;
		}

		sf::Texture* AssetContainer::GetTexturePtr(std::string name)
		{
			Util::ToLowerCase(name);
			const auto it = std::find(myTextureNames.begin(), myTextureNames.end(), name);
			if (it != myTextureNames.end())
			{
				return myTexturePointers.at(std::distance(myTextureNames.begin(), it));
			}
			Log::Warning("AssetContainer::GetTexturePtr(): Texture with name \"" + name + "\" not found!");
			return nullptr;
		}

		SpriteSheetPtr AssetContainer::GetSpriteSheetPtr(std::string name)
		{
			Util::ToLowerCase(name);
			const auto it = std::find(mySpriteSheetNames.begin(), mySpriteSheetNames.end(), name);
			if (it != mySpriteSheetNames.end())
			{
				return mySpriteSheetPointers.at(std::distance(mySpriteSheetNames.begin(), it));
			}
			Log::Warning(
				"AssetContainer::GetSpriteSheetPtr(): Sprite sheet with name \"" + name + "\" not found!");
			return nullptr;
		}


		void AssetContainer::LoadTextures()
		{
			std::ifstream tempTxtFile(FILE_PATHS_FILE_TEXTURES);
			// Acquire file paths
			if (tempTxtFile.is_open())
			{
				std::string tempPath;
				unsigned tempTotalTextures = 0;
				while (std::getline(tempTxtFile, tempPath))
				{
					tempTotalTextures++;
					auto* tempTexture = new sf::Texture();
					if (!tempTexture->loadFromFile(FILEPATH_TEXTURES + tempPath))
					{
						Util::SafeDelete(tempTexture);
						auto msg = "AssetContainer::LoadTextures(): Couldn't load file '" + tempPath + "'";
						Log::Critical(msg);
					}
					else
					{
						myTextureNames.push_back(TrimFileName(tempPath));
						myTexturePointers.push_back(tempTexture);
					}
				}
				tempTxtFile.close();
				Log::Information(
					"AssetContainer::LoadTextures(): " + std::to_string(myTexturePointers.size()) + "/" +
					std::to_string(tempTotalTextures) + " textures loaded!");
			}
			else
			{
				Log::Warning("AssetContainer::LoadTextures(): Unable to load textures!");
			}
		}

		void AssetContainer::LoadAndParseSpriteSheets()
		{
			std::ifstream tempTxtFile(FILE_PATHS_FILES_SPRITE_SHEETS);

			// Acquire file paths
			if (tempTxtFile.is_open())
			{
				unsigned tempTotalSheets = 0;
				std::string tempPath;
				while (std::getline(tempTxtFile, tempPath))
				{
					tempTotalSheets++;

					// Get texture
					auto* tempTexture = new sf::Texture();
					if (!tempTexture->loadFromFile(FILEPATH_SPRITE_SHEETS + tempPath))
					{
						Util::SafeDelete(tempTexture);
						auto msg = "AssetContainer::LoadAndParseSpriteSheets(): Couldn't load file '" + tempPath
							+ "'";
						Log::Critical(msg);
						std::getline(tempTxtFile, tempPath);
						std::getline(tempTxtFile, tempPath);
					}
					else
					{
						mySpriteSheetNames.push_back(TrimFileName(tempPath));

						// Get frame count
						std::getline(tempTxtFile, tempPath);
						const unsigned tempFrameCount = std::stoi(tempPath);

						// Get frame rate
						std::getline(tempTxtFile, tempPath);
						const unsigned tempFrameRate = std::stoi(tempPath);

						// Get rows
						std::getline(tempTxtFile, tempPath);
						const unsigned tempRows = std::stoi(tempPath);

						// Get columns
						std::getline(tempTxtFile, tempPath);
						const unsigned tempCols = std::stoi(tempPath);

						// Create sprite sheet
						auto* tempSheet = new Graphics::SpriteSheet(tempTexture, tempFrameCount, tempFrameRate,
						                                            tempRows, tempCols);

						mySpriteSheetPointers.push_back(tempSheet);
					}
				}
				tempTxtFile.close();
				Log::Information(
					"AssetContainer::LoadAndParseSpriteSheets(): " + std::to_string(mySpriteSheetPointers.size()) + "/"
					+
					std::to_string(tempTotalSheets) + " sprite sheets loaded!");
			}
			else
			{
				Log::Warning("AssetContainer::LoadAndParseSpriteSheets(): Unable load sprite sheets!");
			}
		}

		void AssetContainer::LoadFonts()
		{
			std::ifstream tempTxtFile(FILE_PATHS_FILE_FONTS);

			// Acquire file paths
			if (tempTxtFile.is_open())
			{
				unsigned tempTotalFonts = 0;
				std::string tempPath;
				while (std::getline(tempTxtFile, tempPath))
				{
					tempTotalFonts++;
					auto* tempFont = new sf::Font();
					if (!tempFont->loadFromFile(FILEPATH_FONTS + tempPath))
					{
						Util::SafeDelete(tempFont);
						auto msg = "AssetContainer::LoadFonts(): Couldn't load file '" + tempPath + "'";
						Log::Critical(msg);
					}
					else
					{
						myFontNames.push_back(TrimFileName(tempPath));
						myFontPointers.push_back(tempFont);
					}
				}
				tempTxtFile.close();
				Log::Information(
					"AssetContainer::LoadFonts(): " + std::to_string(myFontPointers.size()) + "/" +
					std::to_string(tempTotalFonts) + " fonts loaded!");
			}
			else
			{
				Log::Warning("AssetContainer::LoadFonts(): Unable load Fonts!");
			}
		}

		const std::string& AssetContainer::TrimFileName(std::string& path)
		{
			path.erase(0, path.find_last_of('/') + 1);
			path.erase(path.find_last_of('.'));
			Util::ToLowerCase(path);
			return path;
		}
	}
}
