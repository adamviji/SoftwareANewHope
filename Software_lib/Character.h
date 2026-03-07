#pragma once
#include <string>
#include <random>

class Character
{
private:
	std::string name;
	std::string greeting;
	std::string randomSentence;

public:
	Character(std::string name, std::string greeting, std::string randomSentence) {
		this->name = name;
		this->greeting = greeting;
		this->randomSentence = randomSentence;
	}

	std::string getName() {
		return this->name;
	}
	std::string getInitialGreeting() {
		return greeting;
	}
	std::string talk() {
		return this->name + " says: " + randomSentence;
	}
};
