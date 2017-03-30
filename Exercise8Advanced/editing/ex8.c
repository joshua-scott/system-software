/*
 Name: 			Exercise8Advanced, ex8.c
 Author: 		Joshua Scott, Robin Jacobs
 Description:
 A command line program that encrypts and decrypts input to/from a specified file using the XOR operator.
 Usage: ./ex8 [e|d] [$filename] [$password]
*/

#include <stdio.h>

void encrypt(char* filename, char* password);
void decrypt(char* filename, char* password);
char* lineEncrypt(char* lineBuffer);

int main (int argc, char** argv)
{
	// If incorrect args, complain
	if (argc != 4){
		printf("Insufficient arguments.");
		return -1;
	}

	char selectedMode = argv[1][0];
	char* filename = argv[2];
	char* password = argv[3]; 

	switch (selectedMode){
		case 'e':
			encrypt(filename, password);
			break;
		case 'd':
			decrypt(filename, password);
			break;
		default :
			printf("Second argument should be e (encrypt), or d (decrypt)");
			return -1;
	}
}

void encrypt(char* filename, char* password){
	printf("Encrypting...\n");
	// open the file
	// write the password to the last line
	// encrypt the whole file
	// display a confirmation message

	// try to open the file
	FILE *file;
	if (!(file = fopen(filename, "w")))
	{
		printf("Error: Check file '%s' exists and you have write permissions.\n", filename);
	}
	// if file exists, read the data line-by-line, encrypt, write back
	else
	{
		char lineBuffer[256] = "";
		int line = 1;

		// read file line-by-line
		while (fgets(lineBuffer, sizeof(lineBuffer), file))
		{
			// encrypt it and re-write the encrypted version
			char* postEncrypted = lineEncrypt(lineBuffer);
			

			//OVERWRITE LINE HERE SOMEHOW


			line++;
		}

		// write ENCRYPTED password to the last line
		fprintf(file, "%s", password);
	}
}

char* lineEncrypt(char* lineBuffer)
{
	// XOR THE INPUT AND RETURN
}

void decrypt(char* filename, char* password){
	printf("Decrypting...\n");
	// open the last line of the file only
	// check the XOR'd password input matches the last line
	// if it does, delete the last line and then decrypt
	// if not, don't edit anything and return an error
}