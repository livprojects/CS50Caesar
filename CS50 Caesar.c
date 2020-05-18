#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

// Checking if it's a digit and there is only one command line argument //


    //If the user doesn't type any key//
    if (argc == 1)
    {
        printf("Please choose one or more digits as a key, non-separated by a blank space.\n");
        return 1;
    }

    else if (argc == 2 && isdigit(*argv[1]))
    {
        printf("Success\n");

        int key = atoi(argv[1]);

        string plaintext = get_string("plaintext:");
        printf("ciphertext:");

        if (key >= 0)
        {

            for (int i = 0; i < strlen(plaintext); i++)
        //The actual converting code//
            {
                if (isalpha(plaintext[i]) && isupper(plaintext[i]))
                {
                    char ciph = (((plaintext[i] + key) - 65) % 26) + 65;
                    printf("%c", ciph);
                }

                else if (isalpha(plaintext[i]) && islower(plaintext[i]))
                {
                    char ciph = (((plaintext[i] + key) - 97) % 26) + 97;
                    printf("%c", ciph);
                }

                else
                {
                    printf("%c", plaintext[i]);
                }

            }
        }


        else
        {
            printf("Please type in a non-negative digit.\n");
            return 1;
        }
    }

    // Directing the user to use only one command line argument and at least one //
    else if (argc != 2 && !isalpha(*argv[1]))
    {
        printf("Please choose one or more digits as a key, non-separated by a blank space.\n");
        return 1;
    }

    //Suggesting to the user to use digits and not alphabetical characters//
    else if (isalpha(*argv[1]))
    {
        printf("Usage:./caesar key\n");
        return 1;
    }
       
    //Handle non numeric key//
       
    else if (!isalnum(*argv[1]))
    {
        printf("Usage:./caesar key\n");
        return 1;
    }

 
    printf("\n");
    return 0;

    
}
