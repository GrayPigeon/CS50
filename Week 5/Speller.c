// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

int numberOfWords = 0;

// Hash table | Array of nodes
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Index of the linked list that word should be stored in
    int index = hash(word);

    // Temp nodes
    node *tmp = malloc(sizeof(node));
    tmp = table[index];

    // While there is a following node
    while (tmp->next != NULL)
    {
        // If you find the word, it is spelled correctly
        if (strcasecmp(tmp->word, word))
        {
            return true;
        }
        // Keep searching for words
        else
        {
            // Move the temp node up the linked list
            tmp = tmp->next;
        }
    }
    // If the word was not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Alphabet
    char *alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Variable to store the first and last letter of the word
    char *firstLast = malloc((sizeof(char) * 2) + 1);
    firstLast[0] = toupper(word[0]);
    firstLast[1] = toupper(word[strlen(word) - 1]);
    firstLast[2] = '\0';

    // If everything was done properly, the index will be changed from 700 to
    // a number between 0 and 676
    int index = 700;

    // Find the proper index
    for (int i = 0; i < 676; i++)
    {
        if (strcmp(table[i]->word, firstLast) == 0)
        {
            index = i;
            free(firstLast);
            return index;
        }
    }
    free(firstLast);
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Alphabet
    char *alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Name the first node of each linked list
    int counter = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int k = 0; k < 26; k++)
        {

            // Each name
            char *name = malloc((sizeof(char) * 2) + 1);
            name[0] = alph[i];
            name[1] = alph[k];
            name[2] = '\0';

            // Create a node
            node *first = malloc(sizeof(node));

            if (first == NULL)
            {
                return false;
            }

            // Set the initial values
            strcpy(first->word, name);
            table[counter] = first;

            // Iterate counter
            counter++;
            free(name);
        }
    }

    // Open the file
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        return false;
    }

    // Each word
    char *word = malloc(LENGTH + 1);
    if (word == NULL)
    {
        return false;
    }

    // Loop until the end of the file when fscanf returns EOF
    while (fscanf(dict, "%s", word) != EOF)
    {

        // Create a new node
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        // Set the value of the node
        strcpy(n->word, word);

        // Index of the particular linked list
        int indexOf = hash(word);

        if (indexOf == 700)
        {
            return false;
        }

        // Set values
        n->next = table[indexOf]->next;

        table[indexOf]->next = n;

        numberOfWords++;
    }
    free(word);
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // Return the global variable that counts each word
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Node to go through the linked list
    node *cursor = malloc(sizeof(node));

    // Helper node to not lose the linked list addresses
    node *tmp = malloc(sizeof(node));
    bool alreadyFreed = false;

    // Go through the lists and free the nodes
    for (int i = 0; i < 676; i++)
    {
        cursor = table[i];
        while (cursor->next != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            alreadyFreed = true;
        }
        free(cursor);

    }
    if (!alreadyFreed)
    {
        free(tmp);
    }
    return true;
}
