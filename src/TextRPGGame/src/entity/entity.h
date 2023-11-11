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
struct Entity
{
    const char *entityType;

    int strength;
    int evasion;
    int critChance;
    int speed;

    int health;
    int armor;
    int mana;
    int stamina;

    Weapon weapon;
};

/* FUNCTION DEFINITIONS */
Entity *setupEntity(EntityType classID);
