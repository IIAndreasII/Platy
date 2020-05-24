#include "DrawManager.h"
#include "..\Super\Entity.h"

std::vector<std::vector<sf::VertexBuffer>> DrawManager::myVertexBuffers;
std::vector<std::vector<Entity*>> DrawManager::myEntityLayers;

DrawManager::~DrawManager()
{
}

void DrawManager::Init()
{
	// TODO: Add vertexbuffers for different tilesets

	myEntityLayers = std::vector<std::vector<Entity*>>();
	for (size_t i = 0; i < DEFAULT_LAYER_COUNT; i++)
	{
		myEntityLayers.push_back(std::vector<Entity*>());
	}
}

void DrawManager::Draw(sf::RenderWindow& aWindow)
{
	// TODO: Add renderstates with tile-textures
	for (auto it : myVertexBuffers)
	{
		for (auto buffer : it)
		{
			aWindow.draw(buffer);

		}
	}

	for (size_t i = 0; i < myEntityLayers.size(); i++)
	{
		for (auto it : myEntityLayers.at(i))
		{
			aWindow.draw(*it);
		}
	}
}

void DrawManager::AddEntity(Entity* anEntity, const unsigned aLayer)
{
	if (aLayer > myEntityLayers.size())
	{
		myEntityLayers.insert(myEntityLayers.begin() + aLayer, std::vector<Entity*>());
	}
	myEntityLayers.at(aLayer).push_back(anEntity);
}

void DrawManager::ChangeLayer(Entity* anEntityPtr, const unsigned aNewLayer)
{
	myEntityLayers.at(aNewLayer).push_back(anEntityPtr);

	for (size_t i = 0; i < myEntityLayers.size(); i++)
	{
		for (size_t j = 0; j < myEntityLayers.at(i).size(); j++)
		{
			if (anEntityPtr == myEntityLayers.at(i).at(j))
			{
				myEntityLayers.at(i).erase(myEntityLayers.at(i).begin() + j);
				break;
			}
		}
	}
}
