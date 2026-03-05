#include "GameObject.h"

GameObject::GameObject(std::string name)
{
	this->name = name;

	std::vector<std::string> interactions = { "look", "open", "move", "turn on", "turn off", "taste", "pick up", "drop" };


	for (int i = 0; i < 4; ++i) {
		int randNr = rand() % interactions.size();

		this->availableInteractions.push_back(std::make_unique<InteractionType>(interactions[randNr]));
	}
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

bool GameObject::selectInteraction(std::string theInteractionType)
{
	for (int i = 0; i < this->availableInteractions.size(); i++) {
		if (this->availableInteractions[i]->toString() == theInteractionType) {
			this->selectedInteraction = std::move(this->availableInteractions[i]);
				return true;
		}
	}
	selectedInteraction = nullptr;
	return false;
}

//std::string GameObject::getSelectedInteraction()
//{
//	return this->selectedInteraction->toString();
//}

std::string GameObject::startSelectedInteraction()
{
	return "You " + this->selectedInteraction->toString() + " " + this->name;
}

void GameObject::abortCurrentInteraction()
{
	this->selectedInteraction = nullptr;
}

std::string GameObject::getName() 
{
	return this->name;
}