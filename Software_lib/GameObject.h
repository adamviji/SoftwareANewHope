#pragma once

#include "InteractionType.h"
#include <vector>
#include <memory>
#include <sstream>
#include <random>

class GameObject {
private:
	std::string name;
	std::unique_ptr<InteractionType> selectedInteraction;
	std::vector<std::unique_ptr<InteractionType>> availableInteractions;

public:
	GameObject(std::string name);
	~GameObject();

	std::string listInteractions();
	bool selectInteraction(std::string theInteractionType);

	//std::string getSelectedInteraction();
	std::string startCurrentInteraction();
	void abortCurrentInteraction();
	std::string getName();
};
