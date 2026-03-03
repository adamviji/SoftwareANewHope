#pragma once

#include "InteractionType.h"
#include <vector>
#include <memory>

class GameObject {
private:
	std::unique_ptr<InteractionType> selectedInteraction;
	std::vector<std::unique_ptr<InteractionType>> availableInteractions;

public:
	GameObject();
	~GameObject();

	std::string interactions();
	void selectInteraction(std::string theInteractionType);

	std::string getSelectedInteraction();
};
