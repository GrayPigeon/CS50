// FAILED ATTEMPT
// FAILED ATTEMPT
// FAILED ATTEMPT
// FAILED ATTEMPT
// FAILED ATTEMPT

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i], name) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (i == j) {
                preferences[i][j] = -1;
            }
        }
    }
    // preferences[0][0] = -1;
    // preferences[1][1] = -1;
    // preferences[2][2] = -1;

    // for (int k = 0; k < candidate_count; k++) {
    //     for (int l = 0; l < candidate_count; l++) {
    //         if (ranks[l] > ranks[k]) {
    //             preferences[k][l]++;
    //         }

    //     }
    // }

    for (int i = 0; i < candidate_count; i++) {
        for (int k = i + 1; k < candidate_count; k++) {
            preferences[ranks[i]][ranks[k]]++;
        }
    }

    // Prints preferences array
    for (int i = 0; i < candidate_count; i++) {
        for (int k = 0; k < candidate_count; k++) {
            printf("%i", preferences[i][k]);
        }
        printf("\n%s\n", "---");
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) {
        for (int k = 0; k < candidate_count; k++) {
            if (preferences[i][k] > preferences[k][i] && preferences[i][k] > 0) {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = k;
                pair_count++;
            } else if (preferences[k][i] > preferences[k][i] && preferences[k][i] > 0) {
                pairs[pair_count].winner = k;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }

    for (int i = 0; i < pair_count; i++) {
        printf("Winner: %s ", candidates[pairs[i].winner]);
        printf("Loser: %s\n", candidates[pairs[i].loser]);
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int strength = 0;
    int strengths[pair_count];
    for (int i = 0; i < pair_count; i++) {
        strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
        strengths[i] = strength;
        // printf("%i", strength);
    }

    for (int i = 0; i < pair_count - 1; i++) {
        for (int k = 0; k < pair_count - i - 1; k++) {
            if (strengths[k] < strengths[k + 1]) {
                int strHelp = strengths[k];
                strengths[k] = strengths[k + 1];
                strengths[k + 1] = strHelp;

                pair help = pairs[k];
                pairs[k] = pairs[k + 1];
                pairs[k + 1] = help;
            }
        }
    }
    // for (int i = 0; i < pair_count; i++) {
    //     printf("%s%i %s%i, ", candidates[pairs[i].winner], strengths[i], candidates[pairs[i].loser], strengths[i]);
    // }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int trus = 0;
    int falls = 0;
    for (int i = 0; i < candidate_count; i++) {


        for (int j = 0; j < candidate_count; j++) {
            for (int k = 0; k < candidate_count; k++) {
                if (j != k) {
                    if (locked[j][k]) {
                        trus++;
                    } else {
                        falls++;
                    }
                }
            }
        }
        for (int j = 0; j < pair_count; j++) {
            if (trus + 1 != falls) {
                locked[pairs[j].winner][pairs[j].loser] = true;
            } else {
                // locked[pairs[j].winner][pairs[j].loser] = false;
                falls++;
                continue;
            }
        }
    }

    // for (int i = 0; i < candidate_count; i++) {
    //     for (int k = 0; k < candidate_count; k++) {
    //         printf("%i", locked[i][k]);
    //     }
    //     printf("\n%s\n", "---");
    // }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int winner = 0;
    for (int j = 0; j < candidate_count; j++) {
        for (int i = 0; i < candidate_count; i++) {
            if (!locked[i][j]) {
                winner = j;
                if (i == candidate_count - 1) {
                    printf("%s", candidates[winner]);
                    return;
                }
                continue;
            } else {
                break;
            }
        }
    }
    return;
}
