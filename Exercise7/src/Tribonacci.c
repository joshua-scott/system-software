#include<stdio.h>
#include"Tribonacci.h"

/*  Checks if a given int is in the Tribonacci sequence. */
void checkIfTribonacci(int toCheck)
{
    // Edge cases
    if (toCheck == 0 || toCheck == 1)
    {
    	printf("Yes, %d is in the Tribonacci sequence.\n", toCheck);
    	return;
    }

	// The first three Tribonacci numbers
	int first = 0;
	int second = 0;
	int third = 1;

	// Adds the preceding three numbers to find the next number in sequence. Checks for equality.
	while (third < toCheck)
	{
		int willBecomeThird = first + second + third;
		if (willBecomeThird == toCheck)
		{
			printf("Yes, %d is in the Tribonacci sequence.\n", toCheck);
			return;
		}
		first = second;
		second = third;
		third = willBecomeThird;
	}
	printf("No, %d is not in the Tribonacci sequence.\n", toCheck);
}
