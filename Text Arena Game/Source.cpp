#include <stdio.h>
#include "equipment.h"
#include "slimeMonster.h"

int main(void)
{
	int playerWeapon = 0;
	int playerChoice;
	int damage;
	int playerHP = 50;

	printf("Welcome to the Aqoris Arena! \nPlease choose a weapon...");
	printf("\n1. Sword\n2. Hammer\n3. Spear\n\n");
	

	do // Determines player weapon
	{
		scanf_s("%d", &playerChoice);

		if (playerChoice == 1)
		{
			playerWeapon = 1;
			damage = sword();
			printf("You chose the sword!\n");
			break;
		}

		else if (playerChoice == 2)
		{
			playerWeapon = 2;
			damage = hammer();
			printf("You chose the hammer!\n");
			break;
		}

		else if (playerChoice == 3)
		{
			playerWeapon = 3;
			damage = spear();
			printf("You chose the spear!\n");
			break;
		}

	} while (playerChoice != 1 || playerChoice != 2 || playerChoice != 3);

	int slimeHP = slimeMonsterHP(); //initialize slime HP
	printf("You've entered combat with a slime!\n");
	
	while (slimeHP >= 0) //initialize combat
	{
		int turnDamage;
		int slimeTurnDamage;
		int blockReduction = 0;
		int heal;

		if (playerHP <= 0) // checks to see if player is alive
		{
			printf("\n---------------------------------------------------\n");
			printf("\nYou Died...\n");
			break;
		}

		printf("\n---------------------------------------------------");
		printf("\nChoose your action!\n1. Attack\n2. Block\n3. Heal\n\n"); // Combat menu
		scanf_s("%d", &playerChoice);
		if (playerChoice == 1) // Deals damage
		{
			turnDamage = damage;
			slimeHP -= turnDamage;
			printf("\nYou dealt %d damage!\n", turnDamage);
		}

		else if (playerChoice == 2) // blocks enemy damage
		{
			blockReduction = block();
			printf("You blocked %d damage!", blockReduction);
		}

		else if (playerChoice == 3) // heals player
		{
	
			heal = healthPot();
			int turnheal = heal;

			if (playerHP == 50)
			{
				turnheal = 0;

				printf("\nYou can't heal above 50 Health.\n"); // stops player from healing above 50 hp if at full hp
			}

			playerHP += turnheal;

			if (playerHP >= 50) // stops player from overhealing
			{
				playerHP = 50;

			}
			printf("\nYou healed for %d Health.\nTo a total of %d Health\n", turnheal, playerHP);
		}

		if (slimeHP >= 0) // checks to see slime health then its turn
		{
			slimeTurnDamage = slimeMonsterDamage() - blockReduction; // determines slime turn damage
			if (slimeTurnDamage <= 0) // catches slime's damage from going negative
			{
				slimeTurnDamage = 0;
			}

			printf("\nSlime's Turn\nIt hit you for %d damage.\n", slimeTurnDamage);
			playerHP = playerHP - slimeTurnDamage;
			printf("You have %d Health remaining\n", playerHP);
		}

		else
		{
			printf("\n---------------------------------------------------\nYou've defeated the slime!"); // victory!
			printf("\nYou Won!\n");
			break;
		}
	}
	
	return 0;
}