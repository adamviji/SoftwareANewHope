#pragma once
#include "../Software_lib/Scene.h"
#include "CharacterInterface.h"


class Game {
private:
	// std::unique_ptr<GameObject> selectedObject;
	std::unique_ptr<Scene> currentScene;
	std::unique_ptr<Scene> playerInventory;
	GameObject* selectedObject;

public:
	CharacterInterface* characterUI;
	Game() : selectedObject(nullptr) {};

	//SETUP
	void setCurrentScene(std::unique_ptr<Scene> s);
	Scene* getCurrentScene() const;

	void setInventory(std::unique_ptr<Scene> s);
	Scene* getInventory() const;

	void addCharacter(std::unique_ptr<Character> c) {
		this->characterUI->addCharacter(std::move(c));
	};

	//INTERACTION WITH OBJECT
	std::string selectObject(const std::string& name);
	bool selectInteraction(const std::string& type);

	std::string startInteraction();
	void abortInteraction();

	std::string getSelectedObjectName() const;
	std::string getSelectedInteractionName() const;

	bool isInConversation(std::string name) {
		return this->characterUI->isActive(name);
	};

	std::string initiateConversation(std::string& name) {
		return this->characterUI->initiateConversation(name);
	}

	std::string sendQuery(std::string message) {
		return this->characterUI->sendQuery(message);
	}

