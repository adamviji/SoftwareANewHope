#include "GameObject.h"

GameObject::GameObject()
{
	
}

GameObject::~GameObject()
{
}

std::string GameObject::listInteractions()
{
	std::stringstream ss;

	ss << "Available interactions: ";

	for (int i = 0; i < this->availableInteractions.size(); ++i) {
		ss << this->availableInteractions[i]->toString() << std::endl;
	}

	return ss.str();
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
