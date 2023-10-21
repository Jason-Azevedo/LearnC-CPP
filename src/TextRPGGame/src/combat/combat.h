#pragma once

/* INCLUDES */
#include "entity.h"

/* FUNCTIONS */
bool combat(Entity *player, Entity *enemy);

void playerAttack(Entity *player, Entity *attacked);
void enemyAttack(Entity *enemy, Entity *player);

void performAttack(WeaponAttackType *attackType, Entity *attacked);

void playerDied();
void enemyDied(Entity *enemy);
