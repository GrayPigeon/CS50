#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(string text, int shift);

int main(int argc, string argv[])
{
    // If the user provides the encryption shift value
    if (argc == 2)
    {
        // Loop through the shift value provided
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // If it is not a digit, the program has 'failed'
            if (!(isdigit(argv[1][i])))
            {
                return 1;
            }
        }

        // Since the shift value is surely a number, convert it from a string to an int
        int shift = atoi(argv[1]);

        // Propt the user for the string to be encrypted
        string text = get_string("plaintext: ");

        // Call the 'encrypt' function
        encrypt(text, shift);
    }
    // If the shift value was not provided
    else
    {
        // Inform the user and terminate the program with a return value of 1
        printf("%s\n", "Expected one command-line argument");
        return 1;
    }
}

void encrypt(string text, int shift)
{
    // Lowercase alphabet
    string alph = "abcdefghijklmnopqrstuvwxyz";

    // Uppercase alphapabet
    string kapp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Special characters
    string special = " .!?,";

    // The new array containing the new encrypted message
    char newText[strlen(text)];

    // Loop through the string to be encrypted
    for (int i = 0; i < strlen(text); i++)
    {
        // If a charactar is a space
        if (text[i] == 32)
        {
            // Add that to the new array
            newText[i] = special[0];
            continue;
        }

        // If the charactar is a period
        else if (text[i] == 46)
        {
            // Add that to the new array
            newText[i] = special[1];
            continue;
        }

        // If the charactar is an exclamation point
        else if (text[i] == 33)
        {
            // Add that to the new array
            newText[i] = special[2];
            continue;
        }

        // If the character is a question mark
        else if (text[i] == 63)
        {
            // Add that to the new array
            newText[i] = special[3];
            continue;
        }

        // If the charactar is a comma
        else if (text[i] == 44)
        {
            // Add that to the new array
            newText[i] = special[4];
            continue;
        }

        // Loop throught the alphabet(s)
        for (int k = 0; k < 25; k++)
        {
            // If the character is equal to a character in the lowercase alphabet
            if (text[i] == alph[k])
            {
                // Declare a variable called key holding the index of the character after encryption
                int key = k + shift;

                // If the key is greater than 25
                if (key > 25)
                {
                    // Determine the remainder, which ultimately is the index of the character after encryption
                    key = key % 26;
                }
                // Add the new character to the new array and break
                newText[i] = alph[key];
                break;
            }
            // If the character is a capital letter
            else if (text[i] == kapp[k])
            {
                // Declare a variable called key holding the index of the character after encryption
                int key = k + shift;

                // If the key is greater than 25
                if (key > 25)
                {

                    // Determine the remainder, which ultimately is the index of the character after encryption
                    key = key % 26;
                }

                // Add the new character to the new array and break
                newText[i] = kapp[key];
                break;
            }
        }
    }
    // Print the new array (the encrypted message)
    printf("ciphertext: %s\n1", newText);
}
