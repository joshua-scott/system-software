#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play();
char initRound();
char* generateChoice();
char determineRoundResult(char* playerChoice, char* cpuChoice);
char parseInput(int confirmOnQuit);
void printOutcome(int outcome);
void printScore(int playerWins, int cpuWins);
void quit(int requireConfirm);
void showAbout();
void showHelp();

int main (void)
{
	srand(time(NULL));
	printf("Welcome to Rock Paper Scissors Lizard Spock!\n");
	printf("At any time, you can type 'a' for about, 'q' to quit, or 'h' for help. Good luck!\n");

	while (1) {
		play();
		printf("Press Enter to play again, or 'q' to quit. ");
		parseInput(0);
	}
}

void play()
{
	int playerWins = 0,
		cpuWins = 0;

	// play rounds until there's a winner
	while (playerWins < 2 && cpuWins < 2) {
		char roundResult = initRound();

		if (roundResult == 'p') {
			printf("you won that round!\n");
			playerWins++;
			printScore(playerWins, cpuWins);
		}
		else if (roundResult == 'c') {
			printf("you lost that round.\n");
			cpuWins++;
			printScore(playerWins, cpuWins);
		}
		else if (roundResult == 'd') {
			printf("That round was a draw, let's play it again...\n");
		}
		else {
			printf("Error at play(), exiting...\n");
			exit(-1);
		}
	}
	
	if (playerWins > 1)
		printf("\nCongratulations, you won Rock Paper Scissors Lizard Spock!\n");
	else
		printf("\nUnlucky, you lost :(\n");
}

char initRound()
{
	char response = ' ';

	do {
		printf("\nEnter Rock(1), Paper(2), Scissors(3), Lizard(4), or Spock(5): ");
		response = parseInput(1);
	} while (response < '1' || response > '5');

	char* playerChoice = malloc(10 * sizeof(char));

	switch (response){
		case '1':
			playerChoice = "Rock"; break;
		case '2':
			playerChoice = "Paper"; break;
		case '3':
			playerChoice = "Scissors"; break;
		case '4':
			playerChoice = "Lizard"; break;
		case '5':
			playerChoice = "Spock"; break;
		default:
			printf("Error at initRound(), exiting...\n");
			exit(-1);
	}

	printf("You chose %s. ", playerChoice);
	return determineRoundResult(playerChoice, generateChoice());
}

char* generateChoice()
{
	int random = rand() % 5;

	char* cpuChoice = malloc(9 * sizeof(char));

	switch (random){
		case 0:
			cpuChoice = "Rock"; break;
		case 1:
			cpuChoice = "Paper"; break;
		case 2:
			cpuChoice = "Scissors"; break;
		case 3:
			cpuChoice = "Lizard"; break;
		case 4:
			cpuChoice = "Spock"; break;
	}

	printf("Your opponent chose %s.\n", cpuChoice);
	return cpuChoice;
}

char determineRoundResult(char* playerChoice, char* cpuChoice)
{
	char result = ' ';
	if (strcmp(playerChoice, cpuChoice) == 0) {
		result = 'd';
	}
	else if (strcmp(playerChoice, "Rock") == 0) {
		if (strcmp(cpuChoice, "Paper") == 0) {
			printOutcome(1); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Scissors") == 0) {
			printOutcome(9); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Lizard") == 0) {
			printOutcome(2); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Spock") == 0) {
			printOutcome(8); 
			result = 'c';
		}		
	}
	else if (strcmp(playerChoice, "Paper") == 0) {
		if (strcmp(cpuChoice, "Rock") == 0) {
			printOutcome(1); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Scissors") == 0) {
			printOutcome(0); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Lizard") == 0) {
			printOutcome(6); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Spock") == 0) {
			printOutcome(7); 
			result = 'p';
		}
	}
	else if (strcmp(playerChoice, "Scissors") == 0) {
		if (strcmp(cpuChoice, "Rock") == 0) {
			printOutcome(9); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Paper") == 0) {
			printOutcome(0); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Lizard") == 0) {
			printOutcome(5); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Spock") == 0) {
			printOutcome(4); 
			result = 'c';
		}
	}
	else if (strcmp(playerChoice, "Lizard") == 0) {
		if (strcmp(cpuChoice, "Rock") == 0) {
			printOutcome(2); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Paper") == 0) {
			printOutcome(6); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Scissors") == 0) {
			printOutcome(5); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Spock") == 0) {
			printOutcome(3); 
			result = 'p';
		}	
	}
	else if (strcmp(playerChoice, "Spock") == 0) {
		if (strcmp(cpuChoice, "Rock") == 0) {
			printOutcome(8); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Paper") == 0) {
			printOutcome(7); 
			result = 'c';
		}
		else if (strcmp(cpuChoice, "Scissors") == 0) {
			printOutcome(4); 
			result = 'p';
		}
		else if (strcmp(cpuChoice, "Lizard") == 0) {
			printOutcome(3); 
			result = 'c';
		}
	}
	return result;
}

void printOutcome(int outcome) {
	switch (outcome) {
		case 0:
			printf("Scissors cut Paper, so "); break;
		case 1:
			printf("Paper covers Rock, so "); break;
		case 2:
			printf("Rock crushes Lizard, so "); break;
		case 3:
			printf("Lizard poisons Spock, so "); break;
		case 4:
			printf("Spock smashes Scissors, so "); break;
		case 5:
			printf("Scissors decapitate Lizard, so "); break;
		case 6:
			printf("Lizard eats Paper, so "); break;
		case 7:
			printf("Paper disproves Spock, so "); break;
		case 8:
			printf("Spock vaporizes Rock, so "); break;
		case 9:
			printf("Rock crushes Scissors, so "); break;
	}
}

void printScore(int playerWins, int cpuWins)
{
	printf("You: %d\tCPU: %d\n", playerWins, cpuWins);
}

void quit(int requireConfirm)
{
	if (requireConfirm)
	{
		printf("Really quit? [y/n] ");
		if (parseInput(0) == 'Y')
			exit(0);
	}
	else
		exit(0);
}

void showAbout()
{
	printf("\nRock Paper Scissors Lizard Spock was popularized by The Big Bang Theory "
			"(the TV show, not the theory).\n"
			"You can read more about it here: " 
			"http://bigbangtheory.wikia.com/wiki/Rock_Paper_Scissors_Lizard_Spock\n"
			"This program was created by Joshua Scott, "
			"for a System Software course at university.\n"
			"You can view more of his work at https://github.com/jscott313\n");
}

void showHelp()
{
	printf("\nBest of three rounds. Rules are as follows:\n"
			"\tScissors cut Paper\n"
			"\tPaper covers Rock\n"
			"\tRock crushes Lizard\n"
			"\tLizard poisons Spock\n"
			"\tSpock smashes Scissors\n"
			"\tScissors decapitate Lizard\n"
			"\tLizard eats Paper\n"
			"\tPaper disproves Spock\n"
			"\tSpock vaporizes Rock\n"
			"\tRock crushes Scissors\n"
			"Simple, right?\n");
}

/**
 * This helper function was implemented due to problems with getchar(), which kept reading the newline as another input.
 * It could be fixed by calling getchar() again, but it's hacky. This function is cleaner.
 * Since all inputs only require one character, returning the first char of whatever the user typed is sufficient.
 */
char parseInput(int confirmOnQuit)
{
	char* input = malloc(10 * sizeof(char));

	if (input)
		fgets(input, 10, stdin);
	else {
		printf("Error at parseInput(), exiting...\n");
		exit(-1);
	}

	char response = toupper(input[0]);
	free(input);

	switch (response) {
		case 'A':
			showAbout(); break;
		case 'H':
			showHelp(); break;
		case 'Q':
			quit(confirmOnQuit); break;
	}

	return response;
}
