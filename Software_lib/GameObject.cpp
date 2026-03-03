#include "GameObject.h"

GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
}

std::string GameObject::interactions()
{
	return std::string();
}

void GameObject::selectInteraction(std::string theInteractionType)
{
	for (int i = 0; i < this->availableInteractions.size(); i++) {
		if (this->availableInteractions[i]->toString() == theInteractionType) {
			this->selectedInteraction = std::move(this->availableInteractions[i]);
		}
	}
}

std::string GameObject::getSelectedInteraction()
{
	return this->selectedInteraction->toString();
}
