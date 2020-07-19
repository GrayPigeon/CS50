#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

void credit(long card);
bool compare_strings(string a, string b);


int main(void) {
    while (true) {
        long card = get_long("Number: ");

        if (card > 0 ) {
            credit(card);
            break;
        }
    }
}

void credit(long card) {
    long size = 0;
    long helperCard = card;

    long oddSum = 0;
    long evenSum = 0;
    long totalSum = oddSum + evenSum;
    long evenDoubleDigits = 0;
    long evenBrokenDownDoubleDigits = 0;
    long oddDoubleDigits = 0;
    long oddBrokenDownDoubleDigits = 0;


    for (int i = 1; helperCard != 0; i++) {
        size = i;
        helperCard /= 10;
    }

    string parity = "odd";

    if (size % 2 == 0) {
        parity = "even";
    }



    for (int i = 1; i <= size; i++) {
        long den = pow(10, (size - i));
        int result = card / den;
        long eachDigit  = result % 10;


        // INDEX 1 IS THE FIRST NUMBER, THERE IS NO INDEX 0 :/
        if (compare_strings(parity, "odd")) {
            // Odd Amount = Odd indices only!
            // If the index is even, skip this index (add 1)
            if (i % 2 != 0) {
                evenSum += eachDigit;
                continue;
            }

            long eachNewDigit = eachDigit;
            oddSum += eachNewDigit * 2;

            if (eachNewDigit > 9) {
                oddDoubleDigits += eachNewDigit * 2;

                int firstDigit = (eachNewDigit * 2) / 10;
                int secondDigit = (eachNewDigit * 2) % 10;
                long totaledIndividualDigits = firstDigit + secondDigit;
                oddBrokenDownDoubleDigits += totaledIndividualDigits;
            }

        } else if (compare_strings(parity, "even")) {
            if (i % 2 == 0) {
                oddSum += eachDigit;
                continue;
            }

            long eachNewDigit = eachDigit;
            evenSum += eachNewDigit * 2;

            if (eachNewDigit > 9) {
                evenDoubleDigits += eachNewDigit * 2;

                int firstDigit = (eachNewDigit * 2) / 10;
                int secondDigit = (eachNewDigit * 2) % 10;
                long totaledIndividualDigits = firstDigit + secondDigit;
                evenBrokenDownDoubleDigits += totaledIndividualDigits;
            }
        }
    }
    oddSum -= oddDoubleDigits;
    oddSum += oddBrokenDownDoubleDigits;
    evenSum -= evenDoubleDigits;
    evenSum += evenBrokenDownDoubleDigits;

    totalSum = oddSum + evenSum;
    // totalSum -= doubleDigits;
    // totalSum += brokenDownDoubleDigits;

    // printf("%i", totalSum);
    if (totalSum % 10 == 0  && totalSum != 0) {
        printf("%s", "VALID!");
    } else {
        printf("%s", "INVALID");
        printf("%ld", totalSum);
    }
}

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
