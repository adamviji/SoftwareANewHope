#pragma once
#include "GameObject.h"
#include "Character.h"


class Scene {
private:
	std::vector<std::unique_ptr<GameObject>> Objects;
	std::string sceneName;
	std::vector<std::unique_ptr<Character>> characters;

public:
	Scene(std::string sceneName);
	~Scene();

	std::string getName();
	void addGameObject(std::unique_ptr<GameObject> obj);
	std::string listAvailableElements() const;
	GameObject* getGameObject(const std::string& sceneName);
	bool isAvailable(const std::string& name) const;

	void addCharacter(std::unique_ptr<Character> c) {
		this->characters.push_back(std::move(c));
	};

	std::string listAvailableCharacters() {
		std::stringstream ss;
		for (int i = 0; i < this->characters.size(); ++i) {
			ss << this->characters[i]->getName() << std::endl;
		}
	}

	std::vector<std::unique_ptr<Character>> getCharacters() {
		return this->characters;
	}
};