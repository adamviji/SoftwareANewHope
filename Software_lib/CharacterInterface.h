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

	void addCharacter(std::unique_ptr<Character> c) { characters.push_back(std::move(c)); }
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
	std::string sendQuery(std::string messege);

	bool isActive();

};


CharacterInterface::~CharacterInterface()
{
}