#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

#include "entity.h"

void printStats(Entity *entity)
{
    std::cout << entity->entityType << " Health: "
              << entity->health << " Mana: "
              << entity->mana << std::endl;
}

void printPlayerAndEntityStats(Entity *player, Entity *enemy)
{
    std::cout << std::endl;
    printStats(player);
    printStats(enemy);
    std::cout << std::endl;
}

void performAttack(WeaponAttackType *attackType, Entity *attacked)
{
    // Remove the entities health based on the attack
    if ((attacked->health - attackType->damage) < 0)
    {
        attacked->health = 0;
        return;
    }

    attacked->health -= attackType->damage;
}

void playerAttack(Entity *player, Entity *enemy)
{
    std::cout << "Choose an attack to perform on " << enemy->entityType << std::endl;

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

    performAttack(&player->weapon.attackTypes[playerOption], enemy);
    printPlayerAndEntityStats(player, enemy);
}

void enemyAttack(Entity *enemy, Entity *player)
{
    srand((unsigned)time(0));

    int randomAttack = (rand() % enemy->weapon.attackTypesCount);
    WeaponAttackType attack = enemy->weapon.attackTypes[randomAttack];

    std::cout << enemy->entityType << " performs " << attack.attackName
              << " attack on you. Damage: (" << attack.damage << ")" << std::endl;

    // Perform the attack
    performAttack(&enemy->weapon.attackTypes[randomAttack], player);
    printPlayerAndEntityStats(player, enemy);
}

// Returns true if the player won
bool combat(Entity *player, Entity *enemy)
{
    int round = 1;

    // If the player is alive and the entity is alive
    while (player->health > 0 && enemy->health > 0)
    {
        std::cout << std::endl
                  << "--------------------------- ROUND " << round << " ---------------------------" << std::endl;

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
