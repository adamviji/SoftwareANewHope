#pragma once
#include <string>

class InteractionType {
private:
	std::string interaction;

public:
	InteractionType(std::string interaction);
	~InteractionType();

	//std::string startInteraction(std::string gameObjectName);

	std::string toString();
};