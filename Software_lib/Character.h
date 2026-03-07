#pragma once
#include <string>

class Character
{
private:
	std::string name;
	std::string greeting;


public:
	Character(std::string name, std::string greeting) {
		this->name = name;
		this->greeting = greeting;
	}

	std::string getName() {
		return this->name;
	}
	std::string getInitialGreeting() {
		return greeting;
	}
	std::string talk(std::string message) {
		return this->name + " says: " + message;
	}
};
