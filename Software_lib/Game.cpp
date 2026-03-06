#include "pch.h"
#include "Game.h"

void Game::setCurrentScene(std::unique_ptr<Scene> s)
{
	this->currentScene = std::move(s);
}

Scene* Game::getCurrentScene() const
{
	return currentScene.get();
}

void Game::setInventory(std::unique_ptr<Scene> s)
{
	this->playerInventory = std::move(s);
}

Scene* Game::getInventory() const
{
	return playerInventory.get();
}

std::string Game::selectObject(const std::string& name)
{
	selectedObject = nullptr;
	if (currentScene)
	{
		auto* object = this->currentScene->getGameObject(name);
		if (object)
		{
			selectedObject = object; 
			return object->getName();
		}
	}
	if (playerInventory)
	{
		auto* object = this->playerInventory->getGameObject(name);
		if (object) 
		{
			selectedObject = object;
			return object->getName();
		}
	}
	return "";
}

bool Game::selectInteraction(const std::string& type)
{
	if (!selectedObject) return false;
	return selectedObject->selectInteraction(type);
}

std::string Game::startInteraction()
{
	if (selectedObject == nullptr)
	{
		return "No object selected.";
	}
	return selectedObject->startCurrentInteraction();
}

void Game::abortInteraction()
{
	if (selectedObject != nullptr)
	{
		selectedObject->abortCurrentInteraction();
	}
	selectedObject = nullptr ;
}

std::string Game::getSelectedObjectName() const
{
	if (selectedObject == nullptr) return "";
	return selectedObject->getName();
}

std::string Game::getSelectedInteractionName() const
{
	if (selectedObject == nullptr) return "";
	return this->selectedObject->getSelectedInteraction();
}
