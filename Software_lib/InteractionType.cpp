#include "InteractionType.h"

InteractionType::InteractionType(std::string interaction)
{
	this->interaction = interaction;
}

InteractionType::~InteractionType()
{
}

//std::string InteractionType::startInteraction(std::string gameObjectName)
//{
//	return "You " + this->toString() + " " + gameObjectName;
//}

std::string InteractionType::toString()
{
	return this->interaction;
}
