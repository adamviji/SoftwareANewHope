#include "Scene.h"

Scene::Scene(std::string sceneName)
{
	this->sceneName = sceneName; 
}

Scene::~Scene()
{
}

std::string Scene::getName()
{
	return this->sceneName;
}

void Scene::addGameObject(std::unique_ptr<GameObject> obj)
{
	Objects.push_back(std::move(obj));
}

std::string Scene::listAvailableElements() const
{
	std::string result;
	for (size_t i = 0; i < Objects.size(); i++)
	{
		result += Objects[i]->getName();
		if (i + 1 < Objects.size()) result += ", ";
	}
	return result;
}

GameObject* Scene::getGameObject(const std::string& Name)
{
	for (auto& obj : Objects)
		if (obj->getName() == Name) return obj.get();
	return nullptr;
}

bool Scene::isAvailable(const std::string& name) const
{
	for (auto& obj : Objects)
		if (obj->getName() == sceneName) return true;
	return false;
}
