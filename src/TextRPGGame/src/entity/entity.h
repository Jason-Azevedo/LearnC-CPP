#pragma once

/* TYPE DEFINITIONS */
typedef struct Entity
{
    unsigned int strength;
    unsigned int evasion;
    unsigned int critChance;

    unsigned int health;
    unsigned int armor;
    unsigned int mana;
    unsigned int stamina;
};

/* FUNCTION DEFINITIONS */
Entity *setupEntity(int classID);
