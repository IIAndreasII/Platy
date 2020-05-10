#include "pch.h"
#include "Scene.h"
#include "Entity.h"

Scene::Scene() :
	myEntities()
{
}

Scene::~Scene()
{
	for (auto it : myEntities)
	{
		SafeDelete(it);
	}
	myEntities.clear();
}

void Scene::Update(const float& deltaTime)
{
	for (auto it : myEntities) 
	{
		it->Update(deltaTime);
	}
}

void Scene::Draw(sf::RenderWindow& aWindow)
{
	for (auto it : myEntities)
	{
		it->Draw(aWindow);
	}
}

void Scene::AddEntity(const EntityPtr anEntity)
{
	myEntities.push_back(anEntity);
}
