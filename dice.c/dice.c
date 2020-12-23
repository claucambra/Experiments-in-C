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


char dice1[] = "  +--------------------------+\n +----------------------------+\n+-|                           |-+\n|-|                           |-|\n|-|                           |-|\n|-|                           |-|\n|-|           XXXXX           |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|           XXXXX           |-|\n|-|                           |-|\n|-|                           |-|\n|-|                           |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
char dice2[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX                   |-|\n|-|  XXXXXXX                  |-|\n|-|  XXXXXXX                  |-|\n|-|   XXXXX                   |-|\n|-|                           |-|\n|-|                           |-|\n|-|                   XXXXX   |-|\n|-|                  XXXXXXX  |-|\n|-|                  XXXXXXX  |-|\n|-|                   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
char dice3[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX                   |-|\n|-|  XXXXXXX                  |-|\n|-|  XXXXXXX                  |-|\n|-|   XXXXX   XXXXX           |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|           XXXXX   XXXXX   |-|\n|-|                  XXXXXXX  |-|\n|-|                  XXXXXXX  |-|\n|-|                   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
char dice4[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n|-|                           |-|\n|-|                           |-|\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
char dice5[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
char dice6[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|                           |-|\n|-|                           |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";



void printDice() {
	int i = 0;
	printf("\n");
	if(sidesDice == 6) {
		while(diceRack[i] != 0) {
			switch(diceRack[i]) {
				case 1:
					puts(dice1);
					break;
				case 2:
					puts(dice2);
					break;
				case 3:
					puts(dice3);
					break;

				case 4:
					puts(dice4);
					break;

				case 5:
					puts(dice5);
					break;

				case 6:
					puts(dice6);
					break;
			}
			i++;
		}
		i = 0;
	}
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
