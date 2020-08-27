#include "AssetContainer.h"
#include <fstream>
#include "Util\Util.h"
#include "Platy.Log/Log.h"
#include "Platy.Core/Util/Util.h"

using namespace Platy::Core;
using namespace Platy::PlatyLog;

constexpr const char* FILEPATHS_FILE_FONTS = "Assets/Filepaths_Fonts.txt";
constexpr const char* FILEPATH_FONTS = "Assets/Fonts/";
constexpr const char* FILEPATHS_FILE_TEXTURES = "Assets/Filepaths_Textures.txt";
constexpr const char* FILEPATH_TEXTURES = "Assets/Textures/Sprites/";
constexpr const char* FILEPATHS_FILES_SPRITESHEETS = "Assets/Filepaths_SpriteSheets.txt";
constexpr const char* FILEPATH_SPRITESHEETS = "Assets/Textures/SpriteSheets/";

std::vector<sf::Texture*> AssetContainer::myTexturePtrs;
std::vector<SpriteSheetPtr> AssetContainer::mySpriteSheetPtrs;
std::vector<sf::Font*> AssetContainer::myFontPtrs;

std::vector<std::string> AssetContainer::myTextureNames;
std::vector<std::string> AssetContainer::mySpriteSheetNames;
std::vector<std::string> AssetContainer::myFontNames;

AssetContainer::~AssetContainer()
{
	for (auto it : myTexturePtrs) 
	{
		Platy::Core::Util::SafeDelete(it);
	}
	for (auto it : mySpriteSheetPtrs)
	{
		Platy::Core::Util::SafeDelete(it);
	}
	for (auto it : myFontPtrs)
	{
		Platy::Core::Util::SafeDelete(it);
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
	std::vector<std::string>::iterator it = std::find(myFontNames.begin(), myFontNames.end(), name);
	if (it != myFontNames.end())
	{
		return myFontPtrs.at(std::distance(myFontNames.begin(), it));
	}
	Log::Warning("AssetContainer::GetFontPtr(): Font with name \"" + name + "\" not found!");
	return new sf::Font();
}

sf::Texture* AssetContainer::GetTexturePtr(std::string name)
{
	Util::ToLowerCase(name);
	std::vector<std::string>::iterator it = std::find(myTextureNames.begin(), myTextureNames.end(), name);
	if (it != myTextureNames.end())
	{
		return myTexturePtrs.at(std::distance(myTextureNames.begin(), it));
	}
	Log::Warning("AssetContainer::GetTexturePtr(): Texture with name \"" + name + "\" not found!");
	return new sf::Texture();
}

SpriteSheetPtr AssetContainer::GetSpritesheetPtr(std::string name)
{
	Util::ToLowerCase(name);
	std::vector<std::string>::iterator it = std::find(mySpriteSheetNames.begin(), mySpriteSheetNames.end(), name);
	if (it != mySpriteSheetNames.end())
	{
		return mySpriteSheetPtrs.at(std::distance(mySpriteSheetNames.begin(), it));
	}
	Log::Warning("AssetContainer::GetSpriteSheetPtr(): Sprite sheet with name \"" + name + "\" not found!");
	return SpriteSheetPtr();
}

void AssetContainer::LoadTextures()
{
	std::ifstream tempTxtFile(FILEPATHS_FILE_TEXTURES);

	// Acquire filepaths
	if (tempTxtFile.is_open())
	{
		std::string tempPath;
		unsigned tempTotalTextures = 0;
		bool tempAllSuccessful = true;
		while (std::getline(tempTxtFile, tempPath))
		{
			tempTotalTextures++;
			sf::Texture* tempTexture = new sf::Texture();
			if (!tempTexture->loadFromFile(FILEPATH_TEXTURES + tempPath))
			{
				Util::SafeDelete(tempTexture);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadTextures(): Couldn't load file '" + tempPath + "'";
				Log::Critical(msg.c_str());
			}
			else
			{
				myTextureNames.push_back(TrimFileName(tempPath));
				myTexturePtrs.push_back(tempTexture);
			}
		}
		tempTxtFile.close();
		Log::Information("AssetContainer::LoadTextures(): " + std::to_string(myTexturePtrs.size()) + "/" + std::to_string(tempTotalTextures) + " textures loaded!");
	}
	else
	{
	Log::Critical("AssetContainer::LoadTextures(): Unable to load textures!");
	}
}

void AssetContainer::LoadAndParseSpriteSheets()
{
	std::ifstream tempTxtFile(FILEPATHS_FILES_SPRITESHEETS);

	// Acquire filepaths
	if (tempTxtFile.is_open())
	{
		unsigned tempTotalSheets = 0;
		bool tempAllSuccessful = true;
		std::string tempPath;
		while (std::getline(tempTxtFile, tempPath))
		{
			tempTotalSheets++;
			
			// Get texture
			sf::Texture* tempTexture = new sf::Texture();
			if (!tempTexture->loadFromFile(FILEPATH_SPRITESHEETS + tempPath))
			{
				Util::SafeDelete(tempTexture);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadAndParseSpriteSheets(): Couldn't load file '" + tempPath + "'";
				Log::Critical(msg.c_str());
				std::getline(tempTxtFile, tempPath);
				std::getline(tempTxtFile, tempPath);
			}
			else
			{	
				mySpriteSheetNames.push_back(TrimFileName(tempPath));
				
				// Get frame count
				std::getline(tempTxtFile, tempPath);
				unsigned tempFrameCount = std::stoi(tempPath);

				// Get frame rate
				std::getline(tempTxtFile, tempPath);
				unsigned tempFrameRate = std::stoi(tempPath);

				// Create spritesheet
				SpriteSheetPtr tempSheet = new SpriteSheet(tempTexture, tempFrameCount, tempFrameRate);
			
				mySpriteSheetPtrs.push_back(tempSheet);
			}
		}
		tempTxtFile.close();
		Log::Information("AssetContainer::LoadAndParseSpriteSheets(): " + std::to_string(mySpriteSheetPtrs.size()) + "/" + std::to_string(tempTotalSheets) + " spritesheets loaded!");
	}
	else
	{
		Log::Critical("AssetContainer::LoadAndParseSpriteSheets(): Unable load spritesheets!");
	}
}

void AssetContainer::LoadFonts()
{
	std::ifstream tempTxtFile(FILEPATHS_FILE_FONTS);

	if (tempTxtFile.is_open())
	{
		unsigned tempTotalFonts = 0;
		bool tempAllSuccessful = true;
		std::string tempPath;
		while (std::getline(tempTxtFile, tempPath))
		{
			tempTotalFonts++;
			sf::Font* tempFont = new sf::Font();
			if (!tempFont->loadFromFile(FILEPATH_FONTS + tempPath))
			{
				Util::SafeDelete(tempFont);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadFonts(): Couldn't load file '" + tempPath + "'";
				Log::Critical(msg.c_str());
			}
			else
			{
				myFontNames.push_back(TrimFileName(tempPath));
				myFontPtrs.push_back(tempFont);
			}
		}
		tempTxtFile.close();
		Log::Information("AssetContainer::LoadFonts(): " + std::to_string(myFontPtrs.size()) + "/" + std::to_string(tempTotalFonts) + " fonts loaded!");
	}
	else
	{
		Log::Critical("AssetContainer::LoadFonts(): Unable load Fonts!");
	}
}

const std::string& AssetContainer::TrimFileName(std::string& tempPath)
{
	tempPath.erase(0, tempPath.find_last_of('/') + 1);
	tempPath.erase(tempPath.find_last_of('.'));
	Util::ToLowerCase(tempPath);
	return tempPath;
}
