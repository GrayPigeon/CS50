#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Cycle through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If the argument candidate is found in the list, add a vote to that candidate and return true
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // To contain the highest number of votes
    int most = candidates[0].votes;

    // To contain the name of the 'most' candidate
    string nameOfMost = "";

    // Cycles through candidates
    for (int i = 1; i < candidate_count; i++)
    {

        // If current candidate has more votes than current highest, most equals current
        if (candidates[i].votes > most)
        {
            most = candidates[i].votes;
            nameOfMost = candidates[i].name;
        }
    }

    // Same loop as before
    for (int i = 0; i < candidate_count; i++)
    {

        // Checks if there are any ties in votes and prints
        if (most == candidates[i].votes && strcmp(nameOfMost, candidates[i].name) != 0)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    printf("%s\n", nameOfMost);
    return;
}
