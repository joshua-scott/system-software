/* play is called where the game logic is stored (calls most/all other functions)
 * player is greeted
 * ask for player's guess
 * generate computer guess
 * check them against each other to see who won that round
 * add a point to the winner
 * tell the user who won that round
 * if someone has 2 points, declare the winner and ask if they want to play again or quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play();
char initRound();
char* generateGuess();
char determineRoundResult(char* guess, char* cpuGuess);
void printOutcome(int outcome);
void printScore(int playerWins, int cpuWins);
void showAbout();
void showHelp();

int main (void)
{
	play();
}

void play()
{
	printf("Welcome to Rock Paper Scissors Lizards Spock!\n");
	printf("At any time, you can type 'a' for about, or 'h' for help. Good luck!\n");

	int playerWins = 0,
		cpuWins = 0;

	// play rounds until there's a winner
	while (playerWins + cpuWins < 3) {
		char roundResult = initRound();

		if (roundResult == 'p') {
			printf("you won that round!\n");
			playerWins++;
			printScore(playerWins, cpuWins);
		}
		else if (roundResult == 'c') {
			printf("you lost that round :(\n");
			cpuWins++;
			printScore(playerWins, cpuWins);
		}
		else {
			printf("That round was a draw, let's play it again...\n");
		}
	}
	
	if (playerWins > 1)
		printf("Congratulations, you won Rock Paper Scissors Lizards Spock!\n");
	else
		printf("Unlucky, you lose :(\n");
}

char initRound()
{
	printf("Enter Rock(1), Paper(2), Scissors(3), Lizard(4), or Spock(5): ");

	char input = getchar();
	char* guess = malloc(9 * sizeof(char));

	switch (input){
		case '1':
			guess = "rock"; break;
		case '2':
			guess = "paper"; break;
		case '3':
			guess = "scissors"; break;
		case '4':
			guess = "lizard"; break;
		case '5':
			guess = "spock"; break;
		case 'a':
			showAbout();
			initRound(); break;
		case 'h':
			showHelp();
			initRound(); break;
		default:
			printf("That's not a valid guess, let's try again...\n");
			initRound(); break;
	}

	printf("You guessed %s. ", guess);

	return determineRoundResult(guess, generateGuess());
}

char* generateGuess()
{
	// generate ascii value from 49 to 53, which is char '1' to '5'
	srand(time(NULL));
	int random = rand() % 5;

	char* cpuGuess = malloc(9 * sizeof(char));

	switch (random){
		case 0:
			cpuGuess = "rock"; break;
		case 1:
			cpuGuess = "paper"; break;
		case 2:
			cpuGuess = "scissors"; break;
		case 3:
			cpuGuess = "lizard"; break;
		case 4:
			cpuGuess = "spock"; break;
	}

	printf("Your opponent guessed %s.\n", cpuGuess);
	return cpuGuess;
}

char determineRoundResult(char* guess, char* cpuGuess)
{
	if (guess == cpuGuess) {
		return 'd';
	}
	if (strcmp(guess, "rock") == 0) {
		if (strcmp(cpuGuess, "paper") == 0) {
			printOutcome(1); return 'c';
		}
		if (strcmp(cpuGuess, "scissors") == 0) {
			printOutcome(9); return 'p';
		}
		if (strcmp(cpuGuess, "lizard") == 0) {
			printOutcome(2); return 'p';
		}
		if (strcmp(cpuGuess, "spock") == 0) {
			printOutcome(8); return 'c';
		}		
	}
	if (strcmp(guess, "paper") == 0) {
		if (strcmp(cpuGuess, "rock") == 0) {
			printOutcome(1); return 'p';
		}
		if (strcmp(cpuGuess, "scissors") == 0) {
			printOutcome(0); return 'c';
		}
		if (strcmp(cpuGuess, "lizard") == 0) {
			printOutcome(6); return 'c';
		}
		if (strcmp(cpuGuess, "spock") == 0) {
			printOutcome(7); return 'p';
		}
	}
	if (strcmp(guess, "scissors") == 0) {
		if (strcmp(cpuGuess, "rock") == 0) {
			printOutcome(9); return 'c';
		}
		if (strcmp(cpuGuess, "paper") == 0) {
			printOutcome(0); return 'p';
		}
		if (strcmp(cpuGuess, "lizard") == 0) {
			printOutcome(5); return 'p';
		}
		if (strcmp(cpuGuess, "spock") == 0) {
			printOutcome(4); return 'c';
		}
	}
	if (strcmp(guess, "lizard") == 0) {
		if (strcmp(cpuGuess, "rock") == 0) {
			printOutcome(2); return 'c';
		}
		if (strcmp(cpuGuess, "paper") == 0) {
			printOutcome(6); return 'p';
		}
		if (strcmp(cpuGuess, "scissors") == 0) {
			printOutcome(5); return 'c';
		}
		if (strcmp(cpuGuess, "spock") == 0) {
			printOutcome(3); return 'p';
		}	
	}
	if (strcmp(guess, "spock") == 0) {
		if (strcmp(cpuGuess, "rock") == 0) {
			printOutcome(8); return 'p';
		}
		if (strcmp(cpuGuess, "paper") == 0) {
			printOutcome(7); return 'c';
		}
		if (strcmp(cpuGuess, "scissors") == 0) {
			printOutcome(4); return 'p';
		}
		if (strcmp(cpuGuess, "lizard") == 0) {
			printOutcome(3); return 'c';
		}	
	}
}

void printOutcome(int outcome) {
	switch (outcome) {
		case 0:
			printf("Scissors cut Paper, so ");
			break;
		case 1:
			printf("Paper covers Rock, so ");
			break;
		case 2:
			printf("Rock crushes Lizard, so ");
			break;
		case 3:
			printf("Lizard poisons Spock, so ");
			break;
		case 4:
			printf("Spock smashes Scissors, so ");
			break;
		case 5:
			printf("Scissors decapitates Lizard, so ");
			break;
		case 6:
			printf("Lizard eats Paper, so ");
			break;
		case 7:
			printf("Paper disproves Spock, so ");
			break;
		case 8:
			printf("Spock vaporizes Rock, so ");
			break;
		case 9:
			printf("Rock crushes Scissors, so ");
			break;
	}
}

void printScore(int playerWins, int cpuWins)
{
	printf("You: %d\tCPU: %d\n", playerWins, cpuWins);
}


void showAbout()
{
	printf("About text will go here.\n");
	do {
		printf("Press Enter to continue playing...");
	} while(getchar() != '\n');
}

void showHelp()
{
	printf("Help text will go here.\n");
	do {
		printf("Press Enter to continue playing...");
	} while(getchar() != '\n');
}
