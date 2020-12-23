#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sidesDice = 6;
int numDice = 2;

int diceRack[100];

void rollDice() {
	memset(diceRack, 0, sizeof diceRack);
	for(int i = 0; i < numDice; i++) {
		diceRack[i] = rand() % sidesDice + 1;
	}
}

void printDice() {
	int i = 0;
	printf("\n");
	while(diceRack[i] != 0) {
		printf("DICE %i: %i\t", i + 1, diceRack[i]); 
		i++;
	}
	printf("\n");
}

char charredNumInput[10];
void setup() {
	printf("\nHow many sides would you like your dice to have? (DEFAULT is %i)\n", sidesDice);
	fgets(charredNumInput, 9, stdin);
	if(atoi(charredNumInput))
		sidesDice = atoi(charredNumInput);
	else
		puts("No number detected.");
	printf("Dice sides set to %i\n", sidesDice);
	memset(charredNumInput, 0, sizeof charredNumInput);

	printf("\nHow many dice would you like to start with? (DEFAULT is %i)\n", numDice);
	fgets(charredNumInput, 9, stdin);
	if(atoi(charredNumInput))
		numDice = atoi(charredNumInput);
	else
		puts("No number detected.");
	printf("Dice sides set to %i\n", numDice);
	memset(charredNumInput, 0, sizeof charredNumInput);

	rollDice();
	printDice();
}

int main() {
	srand(time(NULL));

	setup();

	char input[10];
	do {
		memset(input, 0, sizeof input);
		fgets(input, 9, stdin);
		input[strcspn(input, "\n")] = 0;

		if(strcmp(input, "quit") == 0)
			break;
		else if (strcmp(input, "help") == 0)
			printf("HELP MESSAGE\n");
		else if (strcmp(input, "setup") == 0)
			setup();
		else if (strcmp(input, "roll") == 0) {
			rollDice(); 
			printDice();
		} else {
			puts("No command detected"); 
			continue;
		}
	} while (strcmp(input, "quit") != 0);

	return 0;
}
