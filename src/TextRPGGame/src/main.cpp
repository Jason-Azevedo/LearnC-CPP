#include <iostream>

#include "entity.h"
#include "combat.h"

int main()
{
    // START THE GAME
    std::cout << "----- WELCOME TO THE TEXT RPG GAME -----" << std::endl
              << std::endl;

    std::cout << "Please pick your class:" << std::endl;
    std::cout << "1. Wizard" << std::endl;
    std::cout << "2. Thief" << std::endl;
    std::cout << "3. Knight" << std::endl;

    // Get the user to pick a class
    int classInput;
    std::cout << "Please enter the number of the class you want to be: ";
    std::cin >> classInput;

    // Adjust input to be 0 based then validate user input!
    classInput--;
    if (classInput <= 0 || classInput > 3)
    {
        std::cout << "Invalid input! Please try again..." << std::endl;
        return 1;
    }

    // Initialize our player and first enemy
    Entity *player = setupEntity((EntityType)classInput);
    Entity *goblin = setupEntity(ENTITY_GOBLIN);

    std::cout << "You have chosen: " << player->entityType << std::endl;

    // ACT 1
    std::cout << std::endl
              << "-------------- ACT 1 --------------" << std::endl;
    std::cout << "You have left your hideout and started to embark on your journey when..." << std::endl;
    std::cout << "A " << goblin->entityType << " jumps you..." << std::endl;

    if (combat(player, goblin))
    {
        std::cout << "GAME OVER" << std::endl;
        return 0;
    }

    // TODO: Choose upgrade

    std::cout << std::endl
              << "-------------- ACT 2 --------------" << std::endl;
    std::cout << "You are making your way through the slums when..." << std::endl;

    // TODO: Fight 2 agaisnt wizard thief

    // TODO: Choose different gear item
    std::cout << std::endl
              << "-------------- ACT 3 --------------" << std::endl;
    std::cout << "You did it, you made it to the top of the moutain when..." << std::endl;

    // TODO: Final boss dragaon

    // Exit game
    std::cout << "Thank you for playing! Hope you enjoyed!" << std::endl;

    return 0;
}