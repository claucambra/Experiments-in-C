#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sidesDice = 6;
int numDice = 2;

int diceRack[100];

int rollDice() {
	

	return 0;
}

void setup() {
	char charredNumInput[10];

	printf("How many sides would you like your dice to have? (DEFAULT is %i)\n", sidesDice);
	fgets(charredNumInput, 9, stdin);
	if(atoi(charredNumInput))
		sidesDice = atoi(charredNumInput);
	else
		puts("No number detected.");
	printf("Dice sides set to %i\n", sidesDice);
	memset(charredNumInput, 0, sizeof charredNumInput);

	printf("How many dice would you like to start with? (DEFAULT is %i)\n", numDice);
	fgets(charredNumInput, 9, stdin);
	if(atoi(charredNumInput))
		numDice = atoi(charredNumInput);
	else
		puts("No number detected.");
	printf("Dice sides set to %i\n", numDice);
	memset(charredNumInput, 0, sizeof charredNumInput);

	memset(diceRack, 0, sizeof diceRack);
	for(int i = 0; i < numDice; i++) {
		diceRack[i] = rand() % sidesDice + 1;
	}
}

int main() {
	srand(time(NULL));

	setup();

	int i = 0;
	while(diceRack[i] != 0) {
		printf("DICE %i: %i\n", i + 1, diceRack[i]); 
		i++;
	}
	i = 0;
	
	return 0;
}
