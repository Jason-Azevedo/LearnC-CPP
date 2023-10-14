#include <iostream>

#include "entity.h"

/*
    REQUIREMENTS:
        1. Utils to make this easier to code.
        2. State management, of both the player and enemies.
*/

// TODO: Define the enemy struct

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

    // Determine and set a class for the user with the class input

    Entity *player = setupEntity(classInput);

    // TODO: Fight 1 against goblin

    // TODO: Choose upgrade

    // TODO: Fight 2 agaisnt wizard thief

    // TODO: Choose different gear item

    // TODO: Final boss dragaon

    // Exit game
    std::cout << "Thank you for playing! Hope you enjoyed!" << std::endl;

    return 0;
}