#include<stdio.h>

void displayFileContents();
int checkBytes(char* argv[], int numberOfBytes);
void saveToFile(char *argv[], int numberOfBytes);


int main (int argc, char *argv[])
{
	// If no arguments, we want to display data
	if (argc < 2)
	{
		displayFileContents();
		return 0;
	}
	// Else we check the data and write it
	else
	{
		int numberOfBytes = argc - 1;
		
		if(checkBytes(argv, numberOfBytes))
		{
			// Save binary arguments to file
			saveToFile(argv, numberOfBytes);
		}
		else
		{
			printf("Error: check all arguments are bytes written in binary form.\n");
		}

	}

	return 0;
}

void displayFileContents()
{
	// Open file for reading
	FILE *file;
	file = fopen("binary", "r");

	char readBuffer[80] = "";

	//read from file
	while (fgets(readBuffer, sizeof(readBuffer), file))
	{
		printf("File contents: %s", readBuffer);
	}

	fclose(file);
}

// Check each byte is really 8 bits, by looping through argv
int checkBytes(char* argv[], int numberOfBytes)
{
	int countBits = 0;
	// Inter-argument loop
	for (int currentByte = 1; currentByte <= numberOfBytes; currentByte++)
	{
		// Intra-argument loop
		for (int currentChar = 0; argv[currentByte][currentChar] != '\0'; currentChar++)
		{
			// If the argument contains a non-binary character, display error
			if (!(argv[currentByte][currentChar] == '1' || argv[currentByte][currentChar] == '0'))
				return 0;
			else
				countBits++;
		}

		if (countBits != 8)
			return 0;

		countBits = 0;
	}

	return 1;
}

void saveToFile(char* argv[], int numberOfBytes)
{
	// Open file in a+ mode (append to EOF, create file if it doesn't exist)
	FILE *file;
	file = fopen("binary", "a+");
	
	// To store the string we will write to file
	char writeBuffer[80] = "";
	int writeBufferIndex = 0;

	// Loop through every char in argv and add to writeBuffer[]
	// Inter-argument loop
	for (int currentByte = 1; currentByte <= numberOfBytes; currentByte++)
	{
		// Intra-argument loop
		for (int currentChar = 0; argv[currentByte][currentChar] != '\0'; currentChar++)
		{
			writeBuffer[writeBufferIndex] = argv[currentByte][currentChar];
			writeBufferIndex++;
		}
	}
	// Mark the end of writeBuffer
	writeBuffer[writeBufferIndex] = '\0';

	// Print to file and close
	fprintf(file, "%s\n", writeBuffer);
	fclose(file);
}