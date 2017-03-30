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
	printf("encrypt\n");
	// open the file
	// write the password to the last line
	// encrypt the whole file
	// display a confirmation message
}

void decrypt(char* filename, char* password){
	printf("decrypt\n");
	// open the last line of the file only
	// check the XOR'd password input matches the last line
	// if it does, delete the last line and then decrypt
	// if not, don't edit anything and return an error
}