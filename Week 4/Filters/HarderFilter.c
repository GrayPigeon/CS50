#include "helpers.h"
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy the original image to a non-destructive copy
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            original[i][k] = image[i][k];
        }
    }

    // Declare the convolution matrixes
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Cycle through the image
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // Declaration of way too many variables
            int redHori = 0;
            int greenHori = 0;
            int blueHori = 0;

            int redVerti = 0;
            int greenVerti = 0;
            int blueVerti = 0;

            int redCombined = 0;
            int greenCombined = 0;
            int blueCombined = 0;

            // Cycle through the 9x9 square around each pixel
            for (int a = -1; a < 2; a++)
            {
                // If the current pixel in the square is out of frame, just 'skip' it, which ultimately leaves it's value as black (0)
                for (int b = -1; b < 2; b++)
                {
                    if (i + a < 0 || k + b < 0 || i + a > height - 1 || k + b > width - 1)
                    {
                        continue;
                    }
                    // Here we see some very poor code - Uses the convolution matrix to add to a total
                    redHori += (original[i + a][k + b].rgbtRed * gx[a + 1][b + 1]);
                    greenHori += (original[i + a][k + b].rgbtGreen * gx[a + 1][b + 1]);
                    blueHori += (original[i + a][k + b].rgbtBlue * gx[a + 1][b + 1]);

                    redVerti += (original[i + a][k + b].rgbtRed * gy[a + 1][b + 1]);
                    greenVerti += (original[i + a][k + b].rgbtGreen * gy[a + 1][b + 1]);
                    blueVerti += (original[i + a][k + b].rgbtBlue * gy[a + 1][b + 1]);
                }
            }
            // Final formula to combine Gx and Gy
            redCombined = round(sqrt(pow(redHori, 2) + pow(redVerti, 2)));
            greenCombined = round(sqrt(pow(greenHori, 2) + pow(greenVerti, 2)));
            blueCombined = round(sqrt(pow(blueHori, 2) + pow(blueVerti, 2)));

            // Cap the result at 255
            if (redCombined > 255)
            {
                redCombined = 255;
            }

            if (greenCombined > 255)
            {
                greenCombined = 255;
            }

            if (blueCombined > 255)
            {
                blueCombined = 255;
            }
            // Reassign the pixel its new value
            image[i][k].rgbtRed = redCombined;
            image[i][k].rgbtGreen = greenCombined;
            image[i][k].rgbtBlue = blueCombined;
        }
    }
    return;
}
