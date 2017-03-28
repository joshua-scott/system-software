#include <stdio.h>
#include <stdlib.h>

void displayFileData();
int checkArgsAreBinary(char* argv[], int numberOfArgsToWrite);
void saveToFile(char *argv[], int numberOfArgsToWrite);
void printBinaryAsHex(char* binary);

int main (int argc, char *argv[])
{
	// If no arguments, display data from file
	if (argc < 2)
	{
		displayFileData();
		return 0;
	}
	// If there are arguments, check they are in binary form and write them to file
	else
	{
		int numberOfArgsToWrite = argc - 1;
		
		if(checkArgsAreBinary(argv, numberOfArgsToWrite))
			saveToFile(argv, numberOfArgsToWrite);
		else
			printf("Error: check all arguments are bytes written in binary form.\n");
	}
	return 0;
}

void displayFileData()
{
	// Open file for reading
	FILE *file;
	file = fopen("binary", "r");

	char lineBuffer[256] = "";
	int line = 1;

	// Read file line-by-line
	while (fgets(lineBuffer, sizeof(lineBuffer), file))
	{
		printf("\nLine %i:\n", line);

		// Every time we pass a nibble, print that nibble
		for (int currentBit = 0; lineBuffer[currentBit] != '\n'; currentBit++)
		{
			char previousNibble[4];
			if (currentBit % 4 == 0 && currentBit != 0)
			{
				for (int i = 4; i > 0; i--)
					previousNibble[4 - i] = lineBuffer[currentBit - i];
				printf("Binary: %s\tHex: ", previousNibble);
				printBinaryAsHex(previousNibble);
			}
		}

		line++;
	}

	fclose(file);
}

void printBinaryAsHex (char* binary)
{
	char *a = binary;
	int num = 0;
	do {
	    int b = *a=='1'?1:0;
	    num = (num<<1)|b;
	    a++;
	} while (*a == '1' || *a == '0');
	printf("%X\n", num);
}

// Loop through argv to check each argument is only 1s and 0s
int checkArgsAreBinary(char* argv[], int numberOfArgsToWrite)
{
	// Inter-argument loop
	for (int currentByte = 1; currentByte <= numberOfArgsToWrite; currentByte++)
	{
		// Intra-argument loop
		for (int currentChar = 0; argv[currentByte][currentChar] != '\0'; currentChar++)
		{
			// If the argument contains a non-binary character, return 'false'
			if (!(argv[currentByte][currentChar] == '1' || argv[currentByte][currentChar] == '0'))
				return 0;
		}
	}
	return 1;
}

void saveToFile(char* argv[], int numberOfArgsToWrite)
{
	// Open file in a+ mode (append to EOF, create file if it doesn't exist)
	FILE *file;
	file = fopen("binary", "a+");
	
	// To store the string we will write to file
	char writeBuffer[256] = "";
	int writeBufferIndex = 0;

	// Loop through every char in argv and add to writeBuffer[]
	// Inter-argument loop
	for (int currentByte = 1; currentByte <= numberOfArgsToWrite; currentByte++)
	{
		// Intra-argument loop
		for (int currentChar = 0; argv[currentByte][currentChar] != '\0'; currentChar++)
		{
			writeBuffer[writeBufferIndex] = argv[currentByte][currentChar];
			writeBufferIndex++;
		}
		// Reached the end of an argument so we will write it as a line in the file
		writeBuffer[writeBufferIndex] = '\0';
		fprintf(file, "%s\n", writeBuffer);

		// And reset the variables
		for (int i = 0; i < 256; i++)
		{
			if (writeBuffer[i] != '\0')
				writeBuffer[i] = '\0';
			else break;
		}
		writeBufferIndex = 0;
	}
	fclose(file);
}
