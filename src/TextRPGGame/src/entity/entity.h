#pragma once

#include "weapon.h"

/* ENUMS */
enum EntityType
{
    ENTITY_PLAYER_WIZARD,
    ENTITY_PLAYER_THIEF,
    ENTITY_PLAYER_KNIGHT,
    ENTITY_GOBLIN,
    ENTITY_BANDIT,
    ENTITY_DRAGON
};

/* TYPE DEFINITIONS */
typedef struct Entity
{
    const char *entityType;

    unsigned int strength;
    unsigned int evasion;
    unsigned int critChance;
    unsigned int speed;

    unsigned int health;
    unsigned int armor;
    unsigned int mana;
    unsigned int stamina;

    Weapon weapon;
};

/* FUNCTION DEFINITIONS */
Entity *setupEntity(EntityType classID);
