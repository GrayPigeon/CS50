#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get user input and store it in 'text'
    string text = get_string("Text: ");

    // Counting variables
    float letterCount = 0;
    float sentenceCount = 0;

    // Start at one because at the end of the text, there is no space to count the last word
    float wordCount = 1;

    // Loop that goes through each character of the text
    for (int i = 0; i < strlen(text); i++)
    {

        // If the character's ASCII code is equal to a lowercase or uppercase letter of the alphabet
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letterCount++;
        }

        // If the character is a space, add one to the word counter
        if (text[i] == 32)
        {
            wordCount++;
        }

        // If the charactar is a question mark, exclamation point, or a period, add one to the sentence counter
        if (text[i] == 63 || text[i] == 33 || text[i] == 46)
        {
            sentenceCount++;
        }
    }

    // Average number of letters per 100 words
    float averageLetPer100 = letterCount / wordCount * 100;

    // Average number of sentences per 100 words
    float averageSentencePer100 = sentenceCount / wordCount * 100;


    // Equation with previous variables (Coleman-Liau Formula)
    float index = 0.0588 * averageLetPer100 - 0.296 * averageSentencePer100 - 15.8;

    // If the grade is below one
    if (index < 1)
    {
        printf("Before Grade 1\n");

        // If the grade is above or equal to sixteen
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");

        // Otherwise print the grade normally
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
