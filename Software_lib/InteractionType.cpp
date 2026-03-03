#include "InteractionType.h"

InteractionType::InteractionType(std::string interaction)
{
	this->interaction = interaction;
}

InteractionType::~InteractionType()
{
}

void InteractionType::activate()
{
	// Skip for now
}

std::string InteractionType::toString()
{
	return this->interaction;
}
