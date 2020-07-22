#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void sub(string alph, string plain);
int error(void);

int main(int argc, string argv[])
{
    // If there is one additional command-line argument
    if (argc == 2)
    {
        // Loop that cycles through the command-line argument
        for (int i = 0; i < strlen(argv[1]); i++)
        {

            // Another loop that cycles through the command-line argumnet
            for (int k = i + 1; k < strlen(argv[1]); k++)
            {

                // Compares every letter with every other letter
                if (argv[1][i] == argv[1][k])
                {
                    printf("%s", "NO DUPLICATES ALLOWED");
                    return 1;
                }
            }

            // Determines if each letter is a letter of the alphabet
            int letter = isalpha(argv[1][i]);
            if (letter == 0)
            {
                printf("%s", "INVALID CHARACTER");
                return 1;
            }
        }

        // If the command-line argument length is not 26 (as it should be), return 1;
        if (strlen(argv[1]) != 26)
        {
            printf("%s", "IMPROPER LENGTH");
            return 1;
        }

        // Prompt the user for the text to be encrypted and call substitution method
        string plain = get_string("%s", "plaintext: ");
        sub(argv[1], plain);
    }
    // If there is an improper amount of command-line arguments (or none at all), return 1
    else
    {
        printf("%s", "Print only one command-line argument");
        return 1;
    }
}

void sub(string ciphAlph, string plain)
{
    // Normal alphabet
    string alph = "abcdefghijklmnopqrstuvwxyz";

    // New encrypted text
    char cipher[strlen(plain) + 1];

    // Set last item (space was accommodated for) with termination character
    cipher[strlen(plain)] = '\0';

    // Loop that cycles through the text to be encrypted
    for (int i = 0; i < strlen(plain); i++)
    {

        // Loop that cycles throught the alphabet
        for (int k = 0; k < 26; k++)
        {

            // If the current letter is a letter of the alphabet, regardless of case
            if (plain[i] == alph[k] || plain[i] == toupper(alph[k]))
            {

                // Add new letter to list with the previous case maintained
                if (isupper(plain[i]))
                {
                    cipher[i] = toupper(ciphAlph[k]);
                    break;
                }
                else
                {
                    cipher[i] = tolower(ciphAlph[k]);
                    break;
                }
            }

            // If the letter is not a letter of the alphabet (such as punctuation);
            else
            {
                // If the alphabet loop is finished, just carry over the special character to the new array
                if (k == 25)
                {
                    cipher[i] = plain[i];
                }
            }
        }
    }
    // Print ciphered text
    printf("ciphertext: %s\n", cipher);
}
