#include "pch.h"
#include "TextureContainer.h"
#include <fstream>

#ifdef DEBUG
#include <iostream>
#endif

constexpr const char* FILEPATH = "Textures/Filepaths.txt";

std::vector<TexturePtr> TextureContainer::myTexturePtrs;

TextureContainer::~TextureContainer()
{
	for (auto it : myTexturePtrs) 
	{
		SafeDelete(it);
	}
	myTexturePtrs.clear();
}

void TextureContainer::Init()
{
	myTexturePtrs = std::vector<TexturePtr>();
	LoadTextures();
}

TexturePtr TextureContainer::GetTextureAt(const unsigned index)
{
	return myTexturePtrs.at(index);
}

void TextureContainer::LoadTextures()
{
	std::ifstream tempTxtFile(FILEPATH);
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
#ifdef DEBUG
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
