/*
 * Name: 		Exercise6Advanced, ex6a.c
 * Author: 		Joshua Scott
 * Description:
 *      - A command line program that takes one or more arguments and creates an acronym.
 *      - Any uppercase letters will go into the acronym, lowercase letters will not.
 *      - A warning will be given if there are any non-alpha characters.
 *      - Acronyms will be appended to the file 'output.c'
 */

#include <stdio.h>
#include <ctype.h>

void writeToFile(char* acronym);

int main (int argc, char* argv[])
{
    // to hold the output, 20 chars should be enough for an acronym
    char result[20];

    // check for insufficient arguments
    if (argc < 2)
        printf("Please give at least one word.\n");
    else
    {
        int outputLetter = 0,   // track which letter we're outputting
            alreadyWarned = 0; // track whether we've already warned that non-alpha chars are ignored
        // loop from first word to the last
        for(int currentWord = 1; currentWord < argc; currentWord++)
        {
            // loop through each letter of the current word
            for(int currentLetter = 0; argv[currentWord][currentLetter] != '\0'; currentLetter++)
            {
                // if there's a non-alpha char, warn that it'll be ignored
                if (!isalpha(argv[currentWord][currentLetter]) && !alreadyWarned)
                {
                    printf("Note that non-alpha characters such as '%c' will be ignored.\n", argv[currentWord][currentLetter]);
                    alreadyWarned = 1;
                }
                // if this letter is uppercase, add it to the acronym
                else if (isupper(argv[currentWord][currentLetter]))
                {
                    result[outputLetter] = argv[currentWord][currentLetter];
                    outputLetter++;
                }
            }
        }
        // Output the result and pass it to write to file
        printf("%s\n", result);
        writeToFile(result);
    }
}

void writeToFile(char* acronym)
{
    // open or create the file
    FILE *filePointer;
    filePointer = fopen("output.txt", "a"); // we will append to the end of the file, so previous contents won't be overridden

    // write to the file. passing acronym as an argument to a formatted string fixes the clang error below:
    // "format string is not a string literal (potentially insecure) [-Werror,-Wformat-security]"
    fprintf(filePointer, "%s\n", acronym);

    fclose(filePointer);
}
