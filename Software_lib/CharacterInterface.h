#pragma once
#include "Character.h"
#include <vector>
#include <memory>
#include <string>


class CharacterInterface
{
private:
	Character* currentlyActive;
	//std::vector<std::unique_ptr<Character>> characters;

public:
	CharacterInterface() { this->currentlyActive = nullptr; }
	//~CharacterInterface();

	std::string initiateConversation(Character* c) {
		currentlyActive = c;
		return currentlyActive->getInitialGreeting();
	}
	std::string sendQuery(std::string messege) {
		if (this->currentlyActive == nullptr) {
			return "No character selected";
		}

		return this->currentlyActive->talk(messege);
	};

	

	bool isActive() {
		return this->currentlyActive != nullptr;
	};

};


//CharacterInterface::~CharacterInterface()
//{
//}
