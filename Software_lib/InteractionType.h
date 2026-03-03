#pragma once

#include <string>

class InteractionType {
private:
	std::string interaction;

public:
	InteractionType(std::string interaction);
	~InteractionType();

	void activate();

	std::string toString();
};