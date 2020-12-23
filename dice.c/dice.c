#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Dice defaults
int sides_dice = 6;
int num_dice = 2;

int dice_rack[1000];
int roll_history[10000];

//ASCII art dice
const char dice1[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|                           |-|\n|-|                           |-|\n|-|                           |-|\n|-|           XXXXX           |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|           XXXXX           |-|\n|-|                           |-|\n|-|                           |-|\n|-|                           |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
const char dice2[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX                   |-|\n|-|  XXXXXXX                  |-|\n|-|  XXXXXXX                  |-|\n|-|   XXXXX                   |-|\n|-|                           |-|\n|-|                           |-|\n|-|                   XXXXX   |-|\n|-|                  XXXXXXX  |-|\n|-|                  XXXXXXX  |-|\n|-|                   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
const char dice3[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX                   |-|\n|-|  XXXXXXX                  |-|\n|-|  XXXXXXX                  |-|\n|-|   XXXXX   XXXXX           |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|           XXXXX   XXXXX   |-|\n|-|                  XXXXXXX  |-|\n|-|                  XXXXXXX  |-|\n|-|                   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
const char dice4[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n|-|                           |-|\n|-|                           |-|\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
const char dice5[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX           XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|          XXXXXXX          |-|\n|-|          XXXXXXX          |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|  XXXXXXX         XXXXXXX  |-|\n|-|   XXXXX           XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";
const char dice6[] = "  +---------------------------+\n +-----------------------------+\n+-|                           |-+\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|                           |-|\n|-|                           |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|  XXXXXXX XXXXXXX XXXXXXX  |-|\n|-|   XXXXX   XXXXX   XXXXX   |-|\n+-|                           |-+\n +-----------------------------+\n  +---------------------------+\n";

char commandList[] = "\n\n<---------------------------- COMMANDS ---------------------------->\n\nhelp:\t\tprints this cheat sheet\nsetup:\t\tchoose number of dice and sides of these dice\nstats:\t\tshow statistics about rolls\nroll / ENTER:\troll the dice\nreset:\t\treset the program to default starting state\nquit:\t\tclose this program\n\n";

void roll_dice() {
	int roll_total = 0;
	
	memset(dice_rack, 0, sizeof dice_rack);
	for(int i = 0; i < num_dice; i++) {
		dice_rack[i] = rand() % sides_dice + 1;
		roll_total += dice_rack[i];
	}
	
	int i = 0;
	while(roll_history[i] != 0) {
		i++;
	}
	roll_history[i] = roll_total;
}

void print_dice() {
	int i = 0;
	printf("\n");
	if(sides_dice == 6) { // Print ASCII pictures for 6-sided dice
		while(dice_rack[i] != 0) {
			switch(dice_rack[i]) {
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
	int total = 0;
	while(dice_rack[i] != 0) {
		printf("DICE %i: %i\t", i + 1, dice_rack[i]); 
		total += dice_rack[i];
		i++;
	}
	printf("\nTOTAL: %i\n", total);
}

char charred_num_input[10];
void setup() {
	printf("\nHow many sides would you like your dice to have?\n", sides_dice);
	fgets(charred_num_input, 9, stdin);
	if(atoi(charred_num_input))
		sides_dice = atoi(charred_num_input);
	else
		puts("No number detected.");
	memset(charred_num_input, 0, sizeof charred_num_input);
	
	printf("\nHow many dice would you like to start with?\n", num_dice);
	do {
		if(num_dice > 999)
			puts("Max number of dice is 999");
		
		fgets(charred_num_input, 9, stdin);
		if(atoi(charred_num_input))
			num_dice = atoi(charred_num_input);
		else
			puts("No number detected.");
	} while (num_dice > 999);
	memset(charred_num_input, 0, sizeof charred_num_input);
	
	printf("NEW SETTINGS: Dice sides: %i, Dice amount: %i\n\n", sides_dice, num_dice);
	
	roll_dice();
}

void show_stats() {
	if (roll_history[0] == 0) 
		puts("\nNo stats available yet. Roll the dice!\n");
	else {
		int min_num = roll_history[0], max_num = roll_history[0], nextnum, i = 0;
		while(roll_history[i] != 0) { 
			nextnum = roll_history[i];
			
			if(min_num > nextnum)
				min_num = nextnum;
			
			i++;
		}
		i = 0;
		
		while(roll_history[i] != 0) { 
			nextnum = roll_history[i];
			
			if(max_num < nextnum)
				max_num = nextnum;
			
			i++;
		}
		i = 0;
		
		//Loop prints bar chart
		puts("\nFREQUENCY OF TOTALS:");
		int current_total = 0, this_num_count = 0;
		char bar[200];
		for(int num = min_num; num <= max_num; num++) {
			
			while(roll_history[current_total] != 0) { //Count number of occurrences of each total
				if (roll_history[current_total] == num)
					this_num_count++;
				current_total++;
			}
			
			int barcount;
			for(barcount = 0; barcount < this_num_count; barcount++) { //Draw bar for bar chart
				bar[barcount] = '#';
			}
			bar[barcount] = '\0'; //Prevent garbled string being read
			
			printf("%i:\t%s\n", num, bar);
			
			memset(bar, 0, sizeof bar);
			current_total = 0;
			this_num_count = 0;
		}
	}
	puts("\n");
}

void reset() {
	sides_dice = 6;
	num_dice = 2;
	memset(dice_rack, 0, sizeof dice_rack);
	memset(roll_history, 0, sizeof roll_history);
	puts("\nRESET COMPLETE.\n");
}


int main() {
	srand(time(NULL)); //Random num generator for dice, seed set as current time
	
	puts(commandList);
	printf("DEFAULTS: Dice sides: %i, Dice amount: %i\n\n", sides_dice, num_dice);
	
	char input[10];
	do {
		memset(input, 0, sizeof input);
		fgets(input, 9, stdin);
		input[strcspn(input, "\n")] = 0;
		
		if(strcmp(input, "quit") == 0)
			break;
		else if (strcmp(input, "help") == 0)
			puts(commandList);
		else if (strcmp(input, "setup") == 0)
			setup();
		else if (strcmp(input, "stats") == 0)
			show_stats();
		else if (strcmp(input, "reset") == 0)
			reset();
		else if (strcmp(input, "roll") == 0 || input[0] == '\0') {
			roll_dice(); 
			print_dice();
		} else {
			puts("COMMAND NOT RECOGNISED."); 
			continue;
		}
	} while (strcmp(input, "quit") != 0);
	
	return 0;
}
