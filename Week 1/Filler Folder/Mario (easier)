#include <stdio.h>
#include <cs50.h>
#include <string.h>

void stairs(int n);

int main(void)
{
    // Reprompt user if input is not expected
    while (true) 
    {
        int size = get_int("Height: ");

        // Leave loop if input is as expected (between 1 and 8)
        if (size > 0 && size <= 8)
        {
            stairs(size);
            break;
        }
    }
}

// Prints stairs with spaces to the left
void stairs(int n) 
{
    // Loop for printing each row
    for (int i = 0; i < n; i++)
    {
        // Create an empty 'string' for the hashes (#)
        char hash[1024] = "";

        // Loop for printing each 'column' of each row
        for (int k = 0; k <= i; k++)
        {
            // Create an empty 'string' for the spaces
            char spaces[1024] = "";

            // Loop for determining how many spaces for each row
            for (int l = 1; l < n - i; l++)
            {
                // Add a space to 'spaces' string
                strcat(spaces, " ");
            }
            
            // Add a hash to the 'hash' string
            strcat(hash, "#");

            // If the loop is about to end... (to stay in scope)
            if (k == i) 
            {
                // Add the 'hash' string after the 'spaces' string 
                strcat(spaces, hash);
                
                // Print the 'spaces' string, which now includes the hash string at the back
                printf("%s", spaces);
                
                // New line
                printf("\n");
                
                // Reminder: One row has now been completed
            }
        }
    }
}
