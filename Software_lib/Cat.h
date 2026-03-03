#pragma once

#include <string>

class Cat {
private:
	int	age;
	std::string name;

public:
	Cat();
	Cat(int age);
	Cat(int age, std::string name);
	std::string catSays();
	std::string getName();
	int	getAge();
};