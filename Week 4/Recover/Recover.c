#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // If there is not one command line argument provided
    if (argc != 2)
    {
        printf("%s", "Please add one command-line argument");
        return 1;
    }

    // Open the file provided as a command-line argument
    FILE *file = fopen(argv[1], "r");

    // If the file is empty
    if (file == NULL)
    {
        return 1;
    }

    // Initialize the buffer, filename string, filecounter, and the new image
    unsigned char *buffer = malloc(512);
    char filename[8];
    int fileCounter = 0;
    FILE *img;

    // Loop is for every 512 bytes
    while (fread(buffer, 512, 1, file) == 1)
    {
        // If new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Create a new filename
            sprintf(filename, "%03i.jpg", fileCounter);

            // Create a new image and write to it
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);

            // Add to the new file counter
            fileCounter++;
        }
        // If the file is being continued
        else
        {
            // Continue writing
            fwrite(buffer, 512, 1, img);
        }
    }
    // Close the memory and stuff
    fclose(file);
    fclose(img);
    free(buffer);
    return 0;
}
