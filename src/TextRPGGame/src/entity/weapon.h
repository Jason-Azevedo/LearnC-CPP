#pragma once

/* STRUCT DEFINITIONS */
struct Weapon {
    const char* name;

    WeaponAttackType attackTypes[];
};

struct WeaponAttackType {
    const char* attackName;

    int damage;

    int manaUsage;
    int staminaUsage;
};