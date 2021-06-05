#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int roll_n(void) {
	int dice, roll;
	int sides;
	int status;
	srand((unsigned int)time(0));
	printf("Enter the number of sides per die,0 to stop.\n");
	while (scanf("%d", &sides) == 1 && sides > 0) {
		printf("how many dice?\n");
		if (status = scanf("%d", &dice) != 1) {
			if (status == EOF) {
				break;
			}
			else {
				printf("you should have entered an integer.\n lets begin again.\n");
				while (getchar() != '\n') {
					continue;
				}
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("you have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
		printf("how many sides? enter 0 to stop.\n");
	}
	printf("the rollem() function was called %d times.\n", roll_count);
	printf("good fortune to you!\n");
	return 0;
}