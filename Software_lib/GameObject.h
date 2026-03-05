#pragma once

#include "InteractionType.h"
#include <vector>
#include <memory>
#include <sstream>

class GameObject {
private:
	std::unique_ptr<InteractionType> selectedInteraction;
	std::vector<std::unique_ptr<InteractionType>> availableInteractions;

public:
	GameObject();
	~GameObject();

	std::string listInteractions();
	void selectInteraction(std::string theInteractionType);

	std::string getSelectedInteraction();
};
