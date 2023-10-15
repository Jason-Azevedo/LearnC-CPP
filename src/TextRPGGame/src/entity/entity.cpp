#include "entity.h"

Entity *setupEntity(EntityType entityType)
{
    Entity *entity = new Entity();

    // These could be defined in a data file somewhere and loaded at runtime.
    switch (entityType)
    {
    case ENTITY_PLAYER_WIZARD:
        entity->entityType = "Wizard";
        entity->strength = 5;
        entity->evasion = 12;
        entity->critChance = 5;
        entity->speed = 5;

        entity->health = 100;
        entity->armor = 0;
        entity->mana = 300;
        entity->stamina = 50;

        break;

    case ENTITY_PLAYER_THIEF:
        entity->entityType = "Thief";
        entity->strength = 12;
        entity->evasion = 23;
        entity->critChance = 14;
        entity->speed = 9;

        entity->health = 150;
        entity->armor = 12;
        entity->mana = 60;
        entity->stamina = 220;

        break;

    case ENTITY_PLAYER_KNIGHT:
        entity->entityType = "Knight";
        entity->strength = 30;
        entity->evasion = 5;
        entity->critChance = 6;
        entity->speed = 3;

        entity->health = 450;
        entity->armor = 35;
        entity->mana = 50;
        entity->stamina = 120;

        break;

    case ENTITY_GOBLIN:
        entity->entityType = "Goblin";
        entity->strength = 8;
        entity->evasion = 14;
        entity->critChance = 8;
        entity->speed = 6;

        entity->health = 75;
        entity->armor = 5;
        entity->mana = 0;
        entity->stamina = 150;

        break;
    }

    return entity;
}