#pragma once
#include "../Software_lib/Scene.h"


class Game {
private:
	// std::unique_ptr<GameObject> selectedObject;
	std::unique_ptr<Scene> currentScene;
	std::unique_ptr<Scene> playerInventory;
	GameObject* selectedObject;

public:
	Game() : selectedObject(nullptr) {};

	//SETUP
	void setCurrentScene(std::unique_ptr<Scene> s);
	Scene* getCurrentScene() const;

	void setInventory(std::unique_ptr<Scene> s);
	Scene* getInventory() const;

	//void addCharacter(std::unique_ptr<Character> c) NÅGOT SÅNT?!?!?!

	//INTERACTION WITH OBJECT
	std::string selectObject(const std::string& name);
	bool selectInteraction(const std::string& type);

	std::string startInteraction();
	void abortInteraction();

	std::string getSelectedObjectName() const;
	std::string getSelectedInteractionName() const;


};