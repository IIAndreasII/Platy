#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

constexpr unsigned DEFAULT_LAYER_COUNT = 10;


class Entity;

class DrawManager
{
public:
	~DrawManager();

	static void Init();

	static void Draw(sf::RenderWindow& aWindow);

	static void AddEntity(Entity* anEntity, const unsigned aLayer);
	
	static void ChangeLayer(Entity* anEntityPtr, const unsigned aNewLayer);

private:
	DrawManager();

	// Used for tilesets
	static std::vector<std::vector<sf::VertexBuffer>> myVertexBuffers;

	static std::vector<std::vector<Entity*>> myEntityLayers;
};

#endif