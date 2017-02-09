/*
 ============================================================================
 Name        : Assignment1.c
 Author      : Joshua Scott
 Description : Practicing the use of multiple files
 ============================================================================
 */

#include <stdio.h>
#include "Prime.h"
#include "Tribonacci.h"
#include "OddEven.h"

int main(void) {

	int numberToCheck = 44;

	checkIfPrime(numberToCheck);
	checkIfTribonacci(numberToCheck);
	checkIfOddOrEven(numberToCheck);

}
