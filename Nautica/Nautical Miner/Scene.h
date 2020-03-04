#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/View.hpp"

class Entity;

typedef Entity* EntityPtr;

class Scene
{
public:
	Scene();
	~Scene();

	void Update(const float& deltaTime);
	void Draw(const sf::RenderWindow& aWindow);

	void AddEntity(const EntityPtr anEntity);

private:

	std::vector<EntityPtr> myEntities;




};

#endif