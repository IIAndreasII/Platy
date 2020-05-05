#include "pch.h"
#include "AssetContainer.h"
#include <fstream>

#if DEBUG
#include <iostream>
#endif

constexpr const char* FILEPATH_TEXTURES = "Textures/Filepaths_Textures.txt";
constexpr const char* FILEPATH_SPRITESHEETS = "Assets/Filepaths_SpriteSheets.txt";

std::vector<TexturePtr> AssetContainer::myTexturePtrs;
std::vector<SpriteSheetPtr> AssetContainer::mySpriteSheetPtrs;


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
	myTexturePtrs.clear();
	mySpriteSheetPtrs.clear();
}

void AssetContainer::Init()
{
	myTexturePtrs = std::vector<TexturePtr>();
	LoadTextures();
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
	std::ifstream tempTxtFile(FILEPATH_TEXTURES);
	std::vector<std::string> tempFilePaths = std::vector<std::string>();

	// Acquire filepaths
	if (tempTxtFile.is_open())
	{
		std::string tempPath;
		while (std::getline(tempTxtFile, tempPath))
		{
			tempFilePaths.push_back(tempPath);
		}
		tempTxtFile.close();
	}
#if DEBUG
	else
	{
		std::cout << "TextureContainer:: Unable to open file" << std::endl;
	}
#endif

	// Create pointers and load in files to each one of them
	for (size_t i = 0; i < tempFilePaths.size(); i++)
	{
		myTexturePtrs.push_back(new sf::Texture());
		myTexturePtrs.at(i)->loadFromFile(tempFilePaths.at(i));
	}
}

void AssetContainer::LoadAndParseSpriteSheets()
{
	// TODO: Load in filepath, frame count, frame rate and parse it
}
