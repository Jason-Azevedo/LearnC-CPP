#pragma once

/* STRUCT DEFINITIONS */
struct WeaponAttackType
{
    const char *attackName;

    int damage;

    int manaUsage;
    int staminaUsage;
};

struct Weapon
{
    const char *name;

    WeaponAttackType *attackTypes;
};
