#pragma once
#include "GameObject.h"

class Scene {
private:
	std::vector<std::unique_ptr<GameObject>> availableObjects;
	std::string sceneName;

public:
	Scene();
	~Scene();


};