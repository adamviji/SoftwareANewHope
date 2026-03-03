#include "pch.h"
#include "Cat.h"

Cat::Cat()
{
	this->age = 42;
}

Cat::Cat(int age)
{
	this->age = age;
}

Cat::Cat(int age, std::string name) : Cat(age)
{
	this->name = name;
}

std::string Cat::catSays()
{
	return "meow";
}

std::string Cat::getName()
{
	return this->name;
}

int Cat::getAge()
{
	return this->age;
}