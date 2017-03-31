/*
 * Name: 		Exercise8Advanced, ex8.c
 * Author: 		Joshua Scott
 * Description:
 * 		A command line program that encrypts a file using the XOR operator and a key typed by the user.
 * 		Note that since XOR is symmetrical, the process of decrypting an encrypted file is to simply encrypt it again.
 * 		Usage: ./ex8 inputfile outputfile
 * 		Adapted from http://forum.codecall.net/topic/48889-c-tutorial-xor-encryption/ 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void stripNewline(char* toStrip);
void encryptData(FILE* inputFile, FILE* outputFile, char *key);

int main(int argc, char* argv[])
{
	//Check for valid number of arguments
	if (argc != 3)
	{
		printf("Invalid number of arguments. %d arguments were supplied.\n", argc);
		printf("Usage: %s inputfile outputfile\n", argv[0]);
		exit(0);
	}
	
	FILE* input;
	FILE* output;

	//Open input and output files
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "w");
		

	//Check input file
	if (input == NULL)
	{
		printf("Input file cannot be read.\n");
		exit(0);
	}
		
	//Check output file
	if (output == NULL)
	{
		printf("Output file cannot be written to.\n");
		exit(0);
	}

	//Key strings
	char *key = malloc(MAX_SIZE);

	//Prompt for key
	printf("Passphrase: ");

	//Read in key
	fgets(key, MAX_SIZE, stdin);

	printf("Encrypting %s\n", argv[1]);

	//strip newlines
	stripNewline(key);

	//XOR data and write it to file
	encryptData(input, output, key);
	
	printf("Encrypted data written to %s\n", argv[2]);

	//Release memory
	free(key);

	//Close files
	fclose(input);
	fclose(output);

	return 0;

}


void encryptData(FILE* inputFile, FILE* outputFile, char* key)
{
	int key_count = 0; //Used to restart key if strlen(key) < strlen(encrypt)
	int encrypt_byte;
	
	while( (encrypt_byte = fgetc(inputFile)) != EOF) //Loop through each byte of file until EOF
	{
		//XOR the data and write it to a file
		fputc(encrypt_byte ^ key[key_count], outputFile);

		//Increment key_count and start over if necessary
		key_count++;
		if(key_count == strlen(key))
			key_count = 0;
	}
}

void stripNewline(char* toStrip)
{
	//remove newlines
	if (toStrip[strlen(toStrip) - 1] == '\n')
	{
		toStrip[strlen(toStrip) - 1] = '\0';
	}
}