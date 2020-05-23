#include "pch.h"
#include "AssetContainer.h"
#include <fstream>

#include "Debug.h"


constexpr const char* FILEPATHS_FILE_FONTS = "Assets/Filepaths_Fonts.txt";
constexpr const char* FILEPATH_FONTS = "Assets/Fonts/";
constexpr const char* FILEPATHS_FILE_TEXTURES = "Assets/Filepaths_Textures.txt";
constexpr const char* FILEPATH_TEXTURES = "Assets/Textures/Sprites/";
constexpr const char* FILEPATHS_FILES_SPRITESHEETS = "Assets/Filepaths_SpriteSheets.txt";
constexpr const char* FILEPATH_SPRITESHEETS = "Assets/Textures/SpriteSheets/";

std::vector<TexturePtr> AssetContainer::myTexturePtrs;
std::vector<SpriteSheetPtr> AssetContainer::mySpriteSheetPtrs;
std::vector<FontPtr> AssetContainer::myFontPtrs;


AssetContainer::~AssetContainer()
{
	for (auto it : myTexturePtrs) 
	{
		SafeDelete(it);
	}
	for (auto it : mySpriteSheetPtrs)
	{
		SafeDelete(it);
	}
	for (auto it : myFontPtrs)
	{
		SafeDelete(it);
	}
}

void AssetContainer::Init()
{
	LoadTextures();
	LoadAndParseSpriteSheets();
	LoadFonts();
}

const FontPtr AssetContainer::GetFontPtr(const unsigned index)
{
	return myFontPtrs.at(index);
}

const TexturePtr AssetContainer::GetTexturePtr(const unsigned index)
{
	return myTexturePtrs.at(index);
}

const SpriteSheetPtr AssetContainer::GetSpritesheetPtr(const unsigned index)
{
	return mySpriteSheetPtrs.at(index);
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
				SafeDelete(tempTexture);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadTextures(): Couldn't load file '" + tempPath + "'";
				Debug::Log(msg.c_str(), false);
			}
			else
			{
				myTexturePtrs.push_back(tempTexture);
			}
		}
		tempTxtFile.close();
		std::string msg = "AssetContainer::LoadTextures(): " + std::to_string(myTexturePtrs.size()) + "/" + std::to_string(tempTotalTextures) + " textures loaded!";
		Debug::Log(msg.c_str(), tempAllSuccessful);
	}
	else
	{
		Debug::Log("AssetContainer::LoadTextures(): Unable to load textures!", false);
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
				SafeDelete(tempTexture);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadAndParseSpriteSheets(): Couldn't load file '" + tempPath + "'";
				Debug::Log(msg.c_str(), false);
				std::getline(tempTxtFile, tempPath);
				std::getline(tempTxtFile, tempPath);
			}
			else
			{	
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
		std::string msg = "AssetContainer::LoadAndParseSpriteSheets(): " + std::to_string(mySpriteSheetPtrs.size()) + "/" + std::to_string(tempTotalSheets) + " spritesheets loaded!";
		Debug::Log(msg.c_str(), tempAllSuccessful);
	}
	else
	{
		Debug::Log("AssetContainer::LoadAndParseSpriteSheets(): Unable load spritesheets!", false);
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
			FontPtr tempFont = new sf::Font();
			if (!tempFont->loadFromFile(FILEPATH_FONTS + tempPath))
			{
				SafeDelete(tempFont);
				tempAllSuccessful = false;
				std::string msg = "AssetContainer::LoadFonts(): Couldn't load file '" + tempPath + "'";
				Debug::Log(msg.c_str(), false);
			}
			else
			{
				myFontPtrs.push_back(tempFont);
			}
		}
		tempTxtFile.close();
		std::string msg = "AssetContainer::LoadFonts(): " + std::to_string(myFontPtrs.size()) + "/" + std::to_string(tempTotalFonts) + " fonts loaded!";
		Debug::Log(msg.c_str(), tempAllSuccessful);
	}
	else
	{
		Debug::Log("AssetContainer::LoadFonts(): Unable load Fonts!", false);
	}
}
