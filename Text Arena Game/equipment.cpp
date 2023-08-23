#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "equipment.h"

// Use: sword(); generates a random 2d4 damage number
// Use: hammer(); generates random 1d8 damage
// Use: spear(); generates random 1d6 damage


int sword(void)
{
	srand(time(0));

	int damage;
	int slashing = true;
	damage = (rand() % 8) + 2;

	return damage;
}

int hammer(void)
{
	srand(time(0));

	int damage;
	int bludgeoning = true;
	damage = (rand() % 8) + 1;

	return damage;
}

int spear(void)
{
	srand(time(0));

	int damage;
	int piercing = true;
	damage = (rand() % 6) + 1;

	return damage;
}

int block(void)
{
	srand(time(0));

	int block;
	block = (rand() % 5) + 1;

	return block;
}

int healthPot(void)
{
	srand(time(0));

	int heal;
	heal = ((rand() % 8) + 2) + 2;

	return heal;
}