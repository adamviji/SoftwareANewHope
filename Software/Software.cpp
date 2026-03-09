// Software.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <map>
#include "../Software_lib/Game.h"
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
        {"turnon",     4},
        {"turnoff",    5},
        {"taste",      6},
        {"pickup",     7},
        {"drop",       8},
    };
    //Setup scene
    Game game;
    auto startScene = std::make_unique<Scene>("Start scene");
    startScene->addGameObject(std::make_unique<GameObject>("door"));
    startScene->addGameObject(std::make_unique<GameObject>("chair"));
    startScene->addGameObject(std::make_unique<GameObject>("table"));
    startScene->addGameObject(std::make_unique<GameObject>("gun"));
    startScene->addGameObject(std::make_unique<GameObject>("ammunition"));

    //Setup Inventory
    auto inventory = std::make_unique<Scene>("Inventory");
    inventory->addGameObject(std::make_unique<GameObject>("rocket launcher"));
    inventory->addGameObject(std::make_unique<GameObject>("key"));
    inventory->addGameObject(std::make_unique<GameObject>("cellphone"));
    inventory->addGameObject(std::make_unique<GameObject>("dead rabbit"));
    inventory->addGameObject(std::make_unique<GameObject>("cocain"));
    inventory->addGameObject(std::make_unique<GameObject>("boiling flask"));
    inventory->addGameObject(std::make_unique<GameObject>("emacs device"));
    game.setInventory(std::move(inventory));

    //Setup Character
    // bla bla bla bra färdig kod...
    startScene->addCharacter(std::make_unique<Character>("Bob", "I am bob the builder", "I only know how to build"));
    startScene->addCharacter(std::make_unique<Character>("Shrek", "The name's Shrek, master of the swamp", "This is my swamp get out my swamp"));
    startScene->addCharacter(std::make_unique<Character>("Donkey", "I am THE conquerer of dragons", "I have slayed every dragon known to man"));
    startScene->addCharacter(std::make_unique<Character>("Mafiaman", "Your payment is due", "Im going to give you an offer that you cant refuse"));
    startScene->addCharacter(std::make_unique<Character>("Aladin", "I can show you the world", "let fly away!"));
    game.setCurrentScene(std::move(startScene));

    

    std::cout << "These are your choices" << std::endl;
    std::cout << " scene | inventory | select | interact | talk | say | quit" << std::endl;
 
    std::string cmd = "";
    std::string line, input;

    while (cmd != "quit") {
        std::getline(std::cin, line);
        std::stringstream ss(line);
        ss >> cmd;
        ss >> input;
        //std::cin.ignore();

        switch (commands[cmd]) 
        {
            case 1: 
            {
                std::cout << "You are in " << game.getCurrentScene()->getName() << std::endl;
                std::cout << "Objects available " << game.getCurrentScene()->listAvailableElements() << std::endl;
                std::cout << "These are your available characters " << game.getCurrentScene()->listAvailableCharacters() << std::endl;
                break;
            }
            case 2: 
            {
                std::cout << "Items in inventory " << game.getInventory()->listAvailableElements() << std::endl;
                break;
            }
            case 3:
            {
                //std::cin.ignore();
                //std::string name;
                //std::cin >> name;
                std::string result = game.selectObject(input);
                if (result.empty()) {
                    std::cout << "Object not found" << std::endl;
                }
                else {
                    std::cout << "Object selected: " << result << std::endl;
                    GameObject* obj = game.getCurrentScene()->getGameObject(input);
                    if (obj == nullptr && game.getInventory() != nullptr)
                    {
                        obj = game.getInventory()->getGameObject(input);
                    }
                        if (obj != nullptr)
                    {
                        std::cout << "Available interactions: " << obj->listInteractions() << std::endl;
                    }
                }

                break;
            }
            case 4:
            {
                //std::cin.ignore();
                //std::string type;
                //std::cin >> type;
                if (game.selectInteraction(input) == false)
                {
                    std::cout << "Can't do that..." << std::endl;
                }
                else
                {
                    std::cout << game.startInteraction() << std::endl;
                }
                //switch(interactions[type])
                //{
                //case 1: std::cout << game.selectInteraction("look")    ? game.startInteraction() : "Can't do that. \n"; break;
                //case 2: std::cout << game.selectInteraction("open")    ? game.startInteraction() : "Can't do that. \n"; break;
                //case 3: std::cout << game.selectInteraction("move")    ? game.startInteraction() : "Can't do that. \n"; break;
                //case 4: std::cout << game.selectInteraction("turnon")  ? game.startInteraction() : "Can't do that. \n"; break;
                //case 5: std::cout << game.selectInteraction("turnoff") ? game.startInteraction() : "Can't do that. \n"; break;
                //case 6: std::cout << game.selectInteraction("taste")   ? game.startInteraction() : "Can't do that. \n"; break;
                //case 7: std::cout << game.selectInteraction("pickup")  ? game.startInteraction() : "Can't do that. \n"; break;
                //case 8: std::cout << game.selectInteraction("drop")    ? game.startInteraction() : "Can't do that. \n"; break;
                //}
                break;
            }
            case 5: //talk character
            {
                std::string greeting = game.initiateConversation(input);
                if (greeting.empty())
                {
                    std::cout << "No character of that kind in this scene." << std::endl;
                }
                std::cout << greeting << std::endl;
                break;
            }
            case 6:// say character
            {
                if (game.isInConversation() == false)
                {
                    std::cout << "No active convo, try again fool! type talk <character> to initiate convo Bish." << std::endl;
                }
                else
                {
                    std::cout << game.sendQuery(input) << std::endl;
                }
                break;
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

