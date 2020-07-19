#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

// Function hoisting stuff
void credit(long card);
bool compare_strings(string a, string b);


int main(void)
{
    // Prompts the user for input, if the input is not as expected, re-prompt them
    while (true)
    {
        long card = get_long("Number: ");

        // If the input is as expected, break out of the loop and call the 'credit' function
        if (card > 0)
        {
            credit(card);
            break;
        }
    }
}

void credit(long card)
{
    // Amount of digits
    long size = 0;

    // Non-destructive way to use 'card' variable
    long helperCard = card;

    // Exactly what they sound like
    long oddSum = 0;
    long evenSum = 0;
    long totalSum = 0;

    // Counts the amount of digits (size)
    for (int i = 1; helperCard != 0; i++)
    {
        size = i;
        helperCard /= 10;
    }

    // Default 'parity' value is odd
    string numberParity = "odd";

    // If the number is even, change the 'parity' value to even
    if (size % 2 == 0)
    {
        numberParity = "even";
    }


    // Loop for identifying each individual digit
    for (int i = 1; i <= size; i++)
    {

        // Some really complex math that my brain is too small to explain
        long long den = pow(10, (size - i));
        long result = card / den;

        // Individual digit
        long eachDigit  = result % 10;

        // If the entire number is even
        if (size % 2 == 0)
        {

            // If each digit is odd, multiply each of them by two and add them together
            if (i % 2 != 0)
            {
                long helperDigit = eachDigit * 2;

                // If the multiplied number is double digits
                if (helperDigit > 9)
                {
                    long first = helperDigit / 10;
                    long second = helperDigit % 10;
                    totalSum += first;
                    totalSum += second;
                    // printf("%ld\n", first);
                    // printf("%ld\n", second);
                }
                else
                {
                    totalSum += helperDigit;
                    // printf("%ld\n", helperDigit);
                }
            }
            else
            {
                // If the digit is even, then just add the values to the 'totalSum'
                totalSum += eachDigit;
                continue;
            }
        }
        else
        {
            // If 'eachDigit' is even, multiply each of them by two and add them together
            if (i % 2 == 0)
            {
                // Non-destructive way to mulitply 'eachDigit' by two, as Luhn’s Algorithm explains
                long helperDigit = eachDigit * 2;

                // If the multiplied number is double digits
                if (helperDigit > 9)
                {
                    // Get the first digit of the two digit number
                    long first = helperDigit / 10;

                    // Get the second digit of the two digit number
                    long second = helperDigit % 10;

                    // Add the first and second individual digits to the total
                    totalSum += first;
                    totalSum += second;
                    // printf("%ld\n", first);
                    // printf("%ld\n", second);
                }
                else
                {
                    // If the multiplied digit is single digits, just add it to the total
                    totalSum += helperDigit;
                }
            }
            else
            {
                // If 'eachDigit' is odd just add the values
                totalSum += eachDigit;
                continue;
            }
        }
    }

    // Default type value
    string type = "INVALID";

    // If the values of either of these two variables are one, then further conditions can be satisfied
    int masterCard = 0;
    int amex = 0;

    // Go through each digit
    for (int i = 1; i <= size; i++)
    {
        // Same confusing math stuff as before
        long long den = pow(10, (size - i));
        long result = card / den;

        // Individual digit
        long eachDigit  = result % 10;

        // If this is the first iteration
        if (i == 1)
        {
            // If the first digit is a four, and the size of the entire number is either 13 or 16, there is a chance that it is a
            // VISA card (VISAs must have these conditions satisfied)
            if (eachDigit == 4 && (size == 13 || size == 16))
            {

                // Change the type from 'INVALID' to 'VISA'
                type = "VISA";
                break;

                // If the first digit is a 5, and the size of the entire number is 16, there is a chance that it is
                // A MasterCard (MasterCards must have these conditions satisfied)
            }
            else if (eachDigit == 5 && size == 16)
            {

                // Allows further conditions to be satisfied later
                masterCard = 1;
                continue;

                // If the first digit is a 3, and the size of the entire number is 15, there is a chance that it is
                // An AMEX (AMEXs must have these conditions satisfied)
            }
            else if (eachDigit == 3 && size == 15)
            {

                // Allows further conditions to be satistfied later
                amex = 1;
                continue;
            }
        }

        // If it might be a MasterCard, as previously determined, and this is the second iteration...
        if (masterCard == 1 && i == 2)
        {

            // These are the (second) digit requirements for MasterCards (the first is 5)
            if (eachDigit == 1 || eachDigit == 2 || eachDigit == 3 || eachDigit == 4 || eachDigit ==5)
            {

                // Set the type from 'INVALID' to 'MASTERCARD'
                type = "MASTERCARD";
                break;
            }
        }

        // If it might be an AMEX, as previously determined, and this is the second iteration...
        if (amex == 1 && i == 2)
        {

            // These are the (second) digit requirements for MasterCards (the first is 3)
            if (eachDigit == 4 || eachDigit == 7)
            {

                // Change the type from 'INVALID' to 'AMEX'
                type = "AMEX";
                break;
        }
    }
}

    // If the 'totalSum' variable is divisible by ten evenly, print the type (which still could be 'INVALID')
    if (totalSum % 10 == 0)
    {
        printf("%s\n", type);

    // If the 'totalSum' variable is not divisble by ten evenly, the card is invalid :/
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}

// Function for comparing strings, used from CS50's website
bool compare_strings(string a, string b)
{
    // Compare strings' lengths
    if (strlen(a) != strlen(b))
    {
        return false;
    }

    // Compare strings character by character
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        // Different
        if (a[i] != b[i])
        {
            return false;
        }
    }

    // Same
    return true;
}
