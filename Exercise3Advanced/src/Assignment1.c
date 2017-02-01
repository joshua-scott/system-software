/*
 Name: 			Exercise3Advanced, Assignment1.c
 Author: 		Joshua Scott
 Description:
				1. generates 100 random numbers and places them in a multidimensional array (10 by 10 array)
                2. counts the average of each row and column and prints them either on screen or into a file
                3. sorts the numbers in ascending order and prints the array elements on screen as a 10 by 10 matrix
                4. finds all prime numbers from the array and prints them on the screen
 */

#define ROW 10
#define COLUMN 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototypes
void addRandomIntsTo2DArray(int array[ROW][COLUMN]);
void print2DArray(int array[ROW][COLUMN]);
void calculateAverageOfRow(int array[ROW][COLUMN], int whichRow);
void calculateAverageOfColumn(int array[ROW][COLUMN], int whichColumn);
void sort2DArray(int twoDArray[ROW][COLUMN]);
void bubbleSort(int array[], int length);
void findPrimes(int twoDArray[ROW][COLUMN]);
int checkIfPrime(int toCheck);

int main (void)
{
    // Seed for RNG
    srand(time(NULL));
    int twoDArray[ROW][COLUMN];

    // Task 1, add 100 random numbers to 2D array:
    addRandomIntsTo2DArray(twoDArray);
    printf("Initial array:\n");
    print2DArray(twoDArray);
    printf("\n");

    // Task 2, calculate averages:
    for (int i = 0; i < ROW; i++)
        calculateAverageOfRow(twoDArray, i);
    for (int i = 0; i < COLUMN; i++)
        calculateAverageOfColumn(twoDArray, i);
    printf("\n");

    // Task 3, sort in ascending order and print:
    sort2DArray(twoDArray);
    printf("Array after sorting:\n");
    print2DArray(twoDArray);

    // Task 4, find and display all primes:
    findPrimes(twoDArray);
}

/* Generates random numbers between 0 and 99, adds them to a 2D array. */
void addRandomIntsTo2DArray(int array[ROW][COLUMN])
{
    for (int currentRow = 0; currentRow < ROW; currentRow++)
    {
       for (int currentColumn = 0; currentColumn < COLUMN; currentColumn++)
           array[currentRow][currentColumn] = rand() % 100;
    }
}

/* Prints a 2D array, one row per line, each element taking 2 significant figures. */
void print2DArray(int array[ROW][COLUMN])
{
    for (int currentRow = 0; currentRow < ROW; currentRow++)
    {
       for (int currentColumn = 0; currentColumn < COLUMN; currentColumn++)
           printf("%2d ", array[currentRow][currentColumn]);
       printf("\n");
    }
}

/* Calculates the mean of a specific row of a 2D array. */
void calculateAverageOfRow(int array[ROW][COLUMN], int whichRow)
{
    double currentTotal = 0;

    for (int i = 0; i < COLUMN; i++)
        currentTotal += array[whichRow][i];

    printf("Average of row %d is %.1f\n", whichRow, currentTotal/COLUMN);
}

/* Calculates the mean of a specific column of a 2D array. */
void calculateAverageOfColumn(int array[ROW][COLUMN], int whichColumn)
{
    double currentTotal = 0;

    for (int i = 0; i < ROW; i++)
        currentTotal += array[i][whichColumn];

    printf("Average of column %d is %.1f\n", whichColumn, currentTotal/ROW);
}

/*  Sorts a 2D array in ascending order.
    First copies its elements to a 1D array, sorts that, then copies them back.
    Uses a sister function, bubbleSort, to do the actual sorting.
    Inefficient but simple to code and understand. */
void sort2DArray(int twoDArray[ROW][COLUMN])
{
    int oneDArray[100];

    // Copy 2D array to a 1D array:
    int i = 0;
    for (int currentRow = 0; currentRow < ROW; currentRow++)
    {
       for (int currentColumn = 0; currentColumn < COLUMN; currentColumn++, i++)
           oneDArray[i] = twoDArray[currentRow][currentColumn];
    }

    // Sort the 1D array:
    bubbleSort(oneDArray, ROW * COLUMN);

    // Copy 1D array elements to 2D array:
    i = 0;
    for (int currentRow = 0; currentRow < ROW; currentRow++)
    {
       for (int currentColumn = 0; currentColumn < COLUMN; currentColumn++, i++)
           twoDArray[currentRow][currentColumn] = oneDArray[i];
    }
}

/*  Sorts an array of ints using Bubblesort algorithm.
    Optimised; will not loop again if no swaps were required on the previous loop. */
void bubbleSort(int array[], int length)
{
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swapped = 1;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    } while (swapped);
}

/* Finds and prints elements from a 2D array. Uses function checkIfPrime to do the actual checking. */
void findPrimes(int twoDArray[ROW][COLUMN])
{
    printf("\nPrinting all primes from the given array:\n");
    for (int currentRow = 0; currentRow < ROW; currentRow++)
    {
        for (int currentColumn = 0; currentColumn < COLUMN; currentColumn++)
        {
            if (checkIfPrime(twoDArray[currentRow][currentColumn]))
                printf("%d\n", twoDArray[currentRow][currentColumn]);
        }
    }
    printf("Done.\n");
}

/*  Checks if a given int is prime. Returns 1 if yes, 0 if no. */
int checkIfPrime(int toCheck)
{
    // Edge case
    if (toCheck < 2)
        return 0;

    for (int potentialFactor = toCheck / 2; potentialFactor > 1; potentialFactor--)
    {
        if (toCheck % potentialFactor == 0)
            return 0;
    }
    return 1;
}
