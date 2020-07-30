#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Cycle through the image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Calculate the average rgb value of each pixel
            float sum = image[i][k].rgbtBlue + image[i][k].rgbtRed + image[i][k].rgbtGreen;
            float avg = round(sum / 3);

            // Set the pixel rgb value to the average
            image[i][k].rgbtBlue = avg;
            image[i][k].rgbtRed = avg;
            image[i][k].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Cycle through the image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Original rgb values for each pixel
            float originalRed = image[i][k].rgbtRed;
            float originalGreen = image[i][k].rgbtGreen;
            float originalBlue = image[i][k].rgbtBlue;

            // Formulas for sepia conversion
            float redFormula = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float greenFormula = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float blueFormula = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // If the rgb values are too high, set them to the max
            if (redFormula > 255)
            {
                redFormula = 255;
            }

            if (greenFormula > 255)
            {
                greenFormula = 255;
            }

            if (blueFormula > 255)
            {
                blueFormula = 255;
            }

            // Set the current pixel the proper rounded rgb values
            image[i][k].rgbtRed = round(redFormula);
            image[i][k].rgbtGreen = round(greenFormula);
            image[i][k].rgbtBlue = round(blueFormula);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Cycle through the image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < (width / 2); k++)
        {
            // Swap values on both sides of the image
            RGBTRIPLE tempValue = image[i][k];
            image[i][k] = image[i][width - 1 - k];
            image[i][width - 1 - k] = tempValue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Maintain an original image
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            original[i][k] = image[i][k];
        }
    }

    // Cycle through image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // RGB values and counter
            float redSum = 0;
            float greenSum = 0;
            float blueSum = 0;
            float counter = 0;

            // Cycle through all surrounding pixels of current pixel
            for (int n = -1; n < 2; n++)
            {
                for (int m = -1; m < 2; m++)
                {
                    // If there is no surrounding pixel, add to the counter and continue cycling
                    if (i + n < 0 || i + n > height - 1)
                    {
                        counter++;
                    }
                    else if (k + m < 0 || k + m > width - 1)
                    {
                        counter++;
                    }
                    else
                    {
                        // Add to the rgb sum totals from original array
                        redSum += original[i + n][k + m].rgbtRed;
                        greenSum += original[i + n][k + m].rgbtGreen;
                        blueSum += original[i + n][k + m].rgbtBlue;
                    }
                }
            }
            // Reassign the averaged values to each pixel
            image[i][k].rgbtRed = (round(redSum / (9 - counter)));
            image[i][k].rgbtGreen = (round(greenSum / (9 - counter)));
            image[i][k].rgbtBlue = (round(blueSum / (9 - counter)));
        }
    }
    return;
}
