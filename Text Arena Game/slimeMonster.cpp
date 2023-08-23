#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "slimeMonster.h"

int slimeMonsterHP(void)
{
	srand(time(0));

	int health = 0;
	health = (rand() % 30) + 10;
	
	return health;
}

int slimeMonsterDamage(void)
{
	srand(time(0));

	int damage = 0;
	damage = (rand() % 6) + 1;

	return damage;
}