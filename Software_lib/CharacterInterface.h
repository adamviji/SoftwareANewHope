#pragma once
#include "Character.h"
#include <vector>
#include <memory>
#include <string>


class CharacterInterface
{
private:
	Character* currentlyActive;
	std::vector<std::unique_ptr<Character>> characters;

public:
	CharacterInterface() { this->currentlyActive = nullptr; }
	~CharacterInterface();

	std::string initiateConversation(std::string name) {
		currentlyActive = nullptr;
		for (int i = 0; i < characters.size(); i++)
		{
			if (characters[i]->getName() == name)
			{
				currentlyActive = characters[i].get();
			}
		}
		if (currentlyActive == nullptr) return "";
		return currentlyActive->getInitialGreeting();
	}
	std::string sendQuery(std::string messege) {
		if (this->currentlyActive == nullptr) {
			return "No character selected";
		}

		return this->currentlyActive->talk(messege);
	};

	

	bool isActive(std::string name) {
		if (this->currentlyActive->getName() == name) {
			return true;
		}

		return false;
	};

};


CharacterInterface::~CharacterInterface()
{
}