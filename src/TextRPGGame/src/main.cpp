#include <iostream>

#include "entity.h"
#include "combat.h"

int printGameOver()
{
    std::cout << "GAME OVER" << std::endl;
    return 0;
}

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
    if (classInput <= 0 || classInput > 3)
    {
        std::cout << "Invalid input! Please try again..." << std::endl;
        return 1;
    }

    // Initialize our player and first enemy
    // Adjust to be 0 based.
    classInput--;
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
        return printGameOver();
    }

    free(&goblin);

    std::cout << std::endl
              << "-------------- ACT 2 --------------" << std::endl;
    std::cout << "You are making your way through the slums when..." << std::endl;
    Entity *bandit = setupEntity(ENTITY_BANDIT);

    if (combat(player, goblin))
    {
        return printGameOver();
    }

    free(&bandit);

    std::cout << std::endl
              << "-------------- ACT 3 --------------" << std::endl;
    std::cout << "You did it, you made it to the top of the moutain when..." << std::endl;

    Entity *dragon = setupEntity(ENTITY_DRAGON);

    if (combat(player, dragon))
    {
        return printGameOver();
    }

    free(&dragon);

    // Exit game
    std::cout << std::endl
              << "********************************************" << std::endl;
    std::cout << "Thank you for playing! Hope you enjoyed!" << std::endl;
    std::cout << std::endl
              << "********************************************" << std::endl;

    return 0;
}