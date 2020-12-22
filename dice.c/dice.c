#include <stdio.h>
#include <stdlib.h>

int SIDES = 6;

int diceMaker() {

	return 0;
}

int diceRack[100];



int rollDice() {
	

	return 0;
}

int main() {
	printf("How many sides would you like your dice to have? (DEFAULT is %i)\n", SIDES);
	char charredNumInput[10];
	fgets(charredNumInput, 9, stdin);
	if(atoi(charredNumInput))
		SIDES = atoi(charredNumInput);
	else
		puts("No number detected.");
	printf("Dice sides set to %i\n", SIDES);


	return 0;
}
