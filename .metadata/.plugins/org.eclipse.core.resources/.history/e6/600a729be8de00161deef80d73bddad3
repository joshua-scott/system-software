/*
 Name: 			Exercise2, Assignment1.c
 Author: 		Joshua Scott
 Description: 	A program that:
 	 	 	 	 	1. Counts the sum of even numbers between 0 - 1000.
					2. Prints out every third number between 1000 - 0.
					3. Creates a random number (uses time as seed) and then tells if it is divisible by 2, 3, 5 and 10.
					4. Explains why a computer generated random number is never really random.
					5. Checks if the random number is a number in the Tribonacci sequence.
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Prototype functions
void countEvenNumbers(int maximumNumber);
void printEveryThirdNumberDescending(int maximumNumber);
void checkDivisibility(int dividend, int divisor);
int isTribonacci(int toCheck);

int main (void)
{
	// Task 1
	printf("1.\t");
	countEvenNumbers(1000);

	// Task 2
	printf("2.\t");
	printEveryThirdNumberDescending(1000);

	// Task 3
	printf("3.");
	srand((unsigned int)time(NULL)); // seeds the current time of the system (cast prevents compiler warnings)
	int randomValue = rand(); // generates a random number between 0 and int_max
	checkDivisibility(randomValue, 2);
	checkDivisibility(randomValue, 3);
	checkDivisibility(randomValue, 5);
	checkDivisibility(randomValue, 10);

	// Task 4
	printf("4.\tSince computers follow an algorithm, they can't produce a random number.\n"
			"\tThey are 'pseudo-random' because the generated number depends on the seed.\n"
			"\tIn general, the more unpredictable the seed, the more 'random' the resulting number.\n"
			"\tCommonly used seeds are the system time, or mouse movements (by asking the user to shake their mouse erratically).\n");

	// Task 5
	printf("5.");
	if (isTribonacci(randomValue))
		printf("\tYes, %d is in the Tribonacci sequence\n", randomValue);
	else
		printf("\tNo, %d is not in the Tribonacci sequence\n", randomValue);
}

void countEvenNumbers(int maximumNumber)
{
	int result = 0;
	for(int i = 0; i <= maximumNumber; i += 2)
		result += i;
	printf("%d\n", result);
}

void printEveryThirdNumberDescending(int maximumNumber)
{
	for (int i = maximumNumber; i >= 0; i -= 3)
	{
		printf("%d", i);
		if (i > 2)
			printf(", ");
	}
	printf("\n");
}

void checkDivisibility(int dividend, int divisor)
{
	if (dividend % divisor == 0)
		printf("\tYes, %d is perfectly divisible by %d\n", dividend, divisor);
	else
		printf("\tNo, %d is not perfectly divisible by %d\n", dividend, divisor);
}

int isTribonacci(int toCheck)
{
	if (toCheck == 0)
		return 1;

	// The first three Tribonacci numbers
	int first = 0;
	int second = 0;
	int third = 1;

	// Adds the preceding three numbers to find the next number in sequence. Checks for equality.
	while (third < toCheck)
	{
		int willBecomeThird = first + second + third;
		if (willBecomeThird == toCheck)
			return 1;
		first = second;
		second = third;
		third = willBecomeThird;
	}
	return 0;
}
