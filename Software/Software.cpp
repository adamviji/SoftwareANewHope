// Software.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include "Game.h"
//TODO Interact with character. filer Character + CharacterInterface 
// Lägg till funktioner i Game för detta, initiateConversation & sendQuery.
// kanske en endConversation?



int main()
{
    std::map<std::string, int> commands = {
        {"scene",      1},
        {"inventory",  2},
        {"select",     3},
        {"interact",   4},
        {"talk",       5},
        {"say",        6},
        {"quit",       7},
    };

    std::map<std::string, int> interactions = {
        {"look",       1},
        {"open",       2},
        {"move",       3},
        {"turnOn",     4},
        {"turnOff",    5},
        {"taste",      6},
        {"pickUp",     7},
        {"drop",       8},
    };
    //Setup scene
    Game game;
    auto startScene = std::make_unique<Scene>("Start scene");
    startScene->addGameObject(std::make_unique<GameObject>("door"));
    startScene->addGameObject(std::make_unique<GameObject>("Chair"));
    startScene->addGameObject(std::make_unique<GameObject>("table"));
    startScene->addGameObject(std::make_unique<GameObject>("gun"));
    startScene->addGameObject(std::make_unique<GameObject>("Ammunition"));
    game.setCurrentScene(std::move(startScene));

    //Setup Inventory
    auto inventory = std::make_unique<Scene>("Inventory");
    inventory->addGameObject(std::make_unique<GameObject>("Rocket Launcher"));
    inventory->addGameObject(std::make_unique<GameObject>("key"));
    inventory->addGameObject(std::make_unique<GameObject>("cellphone"));
    inventory->addGameObject(std::make_unique<GameObject>("dead rabbit"));
    inventory->addGameObject(std::make_unique<GameObject>("cocain"));
    inventory->addGameObject(std::make_unique<GameObject>("boiling flask"));
    inventory->addGameObject(std::make_unique<GameObject>("Emacs device"));
    game.setInventory(std::move(inventory));

    //Setup Character
    // bla bla bla bra färdig kod...

    std::cout << "These are your choices" << std::endl;
    std::cout << " scene | inventory | select | interact | talk | say | quit" << std::endl;
    std::string cmd = "";

    while (cmd != "quit") {
        std::cin >> cmd;
        switch (commands[cmd]) 
        {
            case 1: 
            {
                std::cout << "You are in " << game.getCurrentScene()->getName() << std::endl;
                std::cout << "Objects available " << game.getCurrentScene()->listAvailableElements() << std::endl;
                break;
            }
            case 2: 
            {
                std::cout << "Items in inventory " << game.getInventory()->listAvailableElements() << std::endl;
                break;
            }
            case 3:
            {
                std::string name;
                std::cin >> name;
                std::string result = game.selectObject(name);
                if (result.empty()) {
                    std::cout << "Object not found" << std::endl;
                }
                else {
                    GameObject* obj = game.getCurrentScene()->getGameObject(name);
                    if (obj == nullptr) obj = game.getInventory()->getGameObject(name);
                    std::cout << "object selected" << result << std::endl;
                    std::cout << "Available interactions " << obj->listInteractions() << std::endl;
                }
                break;
            }
            case 4:
            {
                std::string type;
                std::cin >> type;
                switch(interactions[type])
                {
                case 1: std::cout << game.selectInteraction("look")    ? game.startInteraction() : "Can't do that. \n"; break;
                case 2: std::cout << game.selectInteraction("open")    ? game.startInteraction() : "Can't do that. \n"; break;
                case 3: std::cout << game.selectInteraction("move")    ? game.startInteraction() : "Can't do that. \n"; break;
                case 4: std::cout << game.selectInteraction("turnon")  ? game.startInteraction() : "Can't do that. \n"; break;
                case 5: std::cout << game.selectInteraction("turnoff") ? game.startInteraction() : "Can't do that. \n"; break;
                case 6: std::cout << game.selectInteraction("taste")   ? game.startInteraction() : "Can't do that. \n"; break;
                case 7: std::cout << game.selectInteraction("pickup")  ? game.startInteraction() : "Can't do that. \n"; break;
                case 8: std::cout << game.selectInteraction("drop")    ? game.startInteraction() : "Can't do that. \n"; break;
                }
                break;
            }
            case 5: //talk
            {

            }
            case 6:// say
            {

            }
            case 7:
            {
                cmd = "quit";
                break;
            }
            default:
            {
                std::cout << "Unknown command!" << std::endl;
                break;
            }
        }
    }
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

