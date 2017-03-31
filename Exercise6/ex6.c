/*
 * Name: 		Exercise6, ex6.c
 * Author: 		Joshua Scott
 * Description:
 *    A command line program that takes one or more arguments and creates an acronym.
 *    Any uppercase letters will go into the acronym, lowercase letters will not.
 */

#include <stdio.h>
#include <ctype.h>

int main (int argc, char* argv[])
{
    // to hold the output, 20 chars should be enough for an acryonym
    char result[20];

    // Check for insufficient arguments
    if (argc < 2)
        printf("Please give at least one word.\n");
    else
    {
        int outputLetter = 0;   // track which letter we're outputting
        // loop from first word to the last
        for(int currentWord = 1; currentWord < argc; currentWord++)
        {
            // loop through each letter of the current word
            for(int currentLetter = 0; argv[currentWord][currentLetter] != '\0'; currentLetter++)
            {
                // if this letter is uppercase, add it to the acronym
                if (isupper(argv[currentWord][currentLetter]))
                {
                    result[outputLetter] = argv[currentWord][currentLetter];
                    outputLetter++;
                }
            }
        }
        // Output the result
        printf("%s\n", result);
    }
}
