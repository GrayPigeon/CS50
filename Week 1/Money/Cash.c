#include <stdio.h>
#include <cs50.h>
#include <math.h>

void greedy(int cash);

int main(void) 
{
    // Loop for re-prompting the user for input if they provide non-expected input
    while (true) 
    {
        // Promt the user for change, take in as a float
        float cash = get_float("Change owed: ");
        
        // Convert the change (decimal) to the amount of cents (whole number) safely using 'round'
        int wholeCash = round(cash * 100);

        // If the input is not as expected, repeat the loop and re-prompt the user
        if (wholeCash > 0)
        {
            greedy(wholeCash);
            break;
        }
    }
}

void greedy(int cash)
{
    // Array for quarters, dimes, nickels, and cents' values
    int arr[4] = {25, 10, 5, 1};

    // What will eventually be the output; the minimum amount of coins required for change
    int count = 0;

    // Loop that cycles through the types of coins array
    for (int i = 0; i < sizeof(arr); i++) 
    {
        // Count += the amount of times that the coin (arr[i]) can be used without overflowing the cash value
        // Because count is an int, if this returns a decimal, it will be truncated, and therefore prevent overflow
        count += cash / arr[i];
        
        // Cash now equals the remainder of the previous equation
        cash = cash % arr[i];
        
        // If cash is 0, if there is no remainder and the arr[i] coin fits into the remaining cash value, exit the loop
        if (cash == 0)
        {
            break;
        }
    }
    // Print the minimum amount of coins required to give change
    printf("%i\n", count);
}
