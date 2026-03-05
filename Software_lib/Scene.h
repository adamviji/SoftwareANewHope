#pragma once
#include "GameObject.h"


class Scene {
private:
	std::vector<std::unique_ptr<GameObject>> Objects;
	std::string sceneName;

public:
	Scene(std::string sceneName);
	~Scene();

	std::string getName();
	void addGameObject(std::unique_ptr<GameObject> obj);
	std::string listAvailableElements() const;
	GameObject* getGameObject(const std::string& sceneName);
	bool isAvailable(const std::string& name) const;

};