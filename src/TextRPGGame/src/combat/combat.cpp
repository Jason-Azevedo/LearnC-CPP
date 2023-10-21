#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

#include "entity.h"

void performAttack(WeaponAttackType *attackType, Entity *attacked)
{
    // Remove the entities health based on the attack
    if ((attacked->health - attackType->damage) > 10000)
        attacked->health = 0;

    attacked->health -= attackType->damage;
}

void playerAttack(Entity *player, Entity *attacked)
{
    std::cout << "Choose an attack to perform on " << attacked->entityType << std::endl;

    int attackOptionCount = player->weapon.attackTypesCount;
    int playerOption = 0;

    while (playerOption <= 0 || playerOption > attackOptionCount)
    {
        // List the options
        for (int i = 0; i < attackOptionCount; i++)
        {
            std::cout << i + 1 << ": " << player->weapon.attackTypes[i].attackName << std::endl;
        }

        // Read the option the player selected
        std::cin >> playerOption;

        // Input is invalid
        if (playerOption <= 0 || playerOption > attackOptionCount)
        {
            std::cout << std::endl
                      << "Invalid input.. please try again.." << std::endl;
            continue;
        }
    }

    performAttack(&player->weapon.attackTypes[playerOption], attacked);
}

void enemyAttack(Entity *enemy, Entity *player)
{
    // Let the enemy attack the player based on what they have.
}

// Returns true if the player won
bool combat(Entity *player, Entity *enemy)
{
    int round = 1;

    // If the player is alive and the entity is alive
    while (player->health > 0 && enemy->health > 0)
    {
        std::cout << std::endl
                  << "ROUND " << round << std::endl;

        // Determine who attacks first
        srand((unsigned)time(0));

        // speed roll
        int playerSpeedRoll = (rand() % 10) + 1;
        int enemySpeedRoll = (rand() % 10) + 1;

        int finalPlayerSpeed = playerSpeedRoll + player->speed;
        int finalEnemySpeed = enemySpeedRoll + enemy->speed;

        // Determine who attacks first
        if (finalPlayerSpeed > finalEnemySpeed)
        {
            // Player is faster, they go first
            playerAttack(player, enemy);
            enemyAttack(enemy, player);
        }
        else
        {
            // Enemy is faster, they go first
            enemyAttack(enemy, player);
            playerAttack(player, enemy);
        }

        round++;
    }

    // Did the player win the fight?
    return player->health > 0;
}
