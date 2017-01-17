/*
 Name: 			Assignment2.c
 Author: 		Joshua Scott and Robin Jacobs (1503969 and 1503968)
 Description: 	A program that can count (sum, difference, product, division and power).
 */

#include<stdio.h>
#include<math.h>

int main (void)
{
	// Variable declarations
	const int firstNumber = 9;
	const int secondNumber = 4;
	int result = 0;

	printf("First number:\t%d\n", firstNumber);
	printf("Second number:\t%d\n", secondNumber);

	// We can store the result in the variable 'result' and then print, like so:
	result = firstNumber + secondNumber;
	printf("Sum:\t\t%d\n", result);

	// Or just embed the calculation within the printf arguments:
	printf("Difference:\t%d\n", firstNumber - secondNumber);
	printf("Product:\t%d\n", firstNumber * secondNumber);
	printf("Division:\t%d\n", firstNumber / secondNumber);
	printf("Power:\t\t%.0f\n", pow(firstNumber, secondNumber));
}
