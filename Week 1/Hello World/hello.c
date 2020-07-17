#include <stdio.h>
#include <cs50.h>

// Function that prints inquires the user's name, and returns the string: "Hello, [name]!"
int main(void) 
{
    // Inquire name
    string name = get_string("What is your name!\n");
    
    // Say hi
    printf("Hello, %s!\n", name);
}
