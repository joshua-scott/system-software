/*
 * Name: 		Exercise7, ex7.c
 * Author: 		Joshua Scott
 * Description: Practicing the use of multiple files
 */

#include <stdio.h>
#include "Prime.h"
#include "Tribonacci.h"
#include "OddEven.h"

int main(void) {
	
	int numberToCheck = 73;

	checkIfPrime(numberToCheck);
	checkIfTribonacci(numberToCheck);
	checkIfOddOrEven(numberToCheck);
}
