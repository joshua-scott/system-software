/*
 * test.c
 *
 *  Created on: 6 Feb 2017
 *      Author: Robin Jacobs
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int atomicNumber;
	char chemicalSymbol[3];
	char elementName[14];
	char elementState[2];
} elements;
elements periodicTable[118];
char *item;

/* Prototype functions */
int readFile();
void printContents();

int main()
{
	readFile();
	return 0;
}

int readFile()
{
	FILE *dataFile = fopen("Periodic_Table.csv", "r");
	char readBuffer[30];
	int counter = 0;
	if (!dataFile) /* is file valid? If not, error message and exit */
	{
		printf("File does not exist or could not be opened.\n");
		return 1;
	}
	while (fgets(readBuffer,sizeof(readBuffer), dataFile))
	{
//		printf("%s",buffer);

		/* atoi deprecated in favour of strtol, but long int not needed and atoi has less required arguments (which aren't needed here)*/
		item = strtok(readBuffer,";");
//		printf("%s\n",item);
		periodicTable[counter].atomicNumber = atoi(item);

		item = strtok(NULL,";");
//		printf("%s\n",item);
		strcpy(periodicTable[counter].chemicalSymbol,item);

		item = strtok(NULL,";");
//		printf("%s\n",item);
		strcpy(periodicTable[counter].elementName,item);

		item = strtok(NULL,"\n");
//		printf("%s\n",item);
		strcpy(periodicTable[counter].elementState,item);

		counter++;
	}
	fclose(dataFile);
	printContents();
	return 0;
}

/*goes through every entry in the struct array sequentially and prints it*/
void printContents()
{
	for (int i=0; i<118; i++)
	{
		printf("%d %s %s %s\n", periodicTable[i].atomicNumber, periodicTable[i].chemicalSymbol,
								periodicTable[i].elementName, periodicTable[i].elementState);
	}
}
