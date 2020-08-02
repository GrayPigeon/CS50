**Runoff (Easier Assignment)**

Instructions (paraphrased): 
1. Complete the 'vote' function
    - The function takes arguments voter, rank, and name. If name is a match for the name of a valid candidate, then you should update the global preferences array to indicate that the voter voter has that candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.).
    - If the preference is successfully recorded, the function should return true; the function should return false otherwise (if, for instance, name is not the name of one of the candidates).
    - You may assume that no two candidates will have the same name.
2. Complete the 'tabulate' function
    - The function should update the number of votes each candidate has at this stage in the runoff.
    - Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.
3. Complete the 'print_winner' function
    - If any candidate has more than half of the vote, their name should be printed to stdout and the function should return true.
    - If nobody has won the election yet, the function should return false.
4. Complete the 'find_min' function
    - The function should return the minimum vote total for any candidate who is still in the election.
5. Complete the 'is_tie' function
    - The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
    - The function should return true if every candidate remaining in the election has the same number of votes, and should return false otherwise.
6. Complete the 'eliminate' function
    - The function takes an argument min, which will be the minimum number of votes that anyone in the election currently has.
    - The function should eliminate the candidate (or candidates) who have min number of votes.

```
Example:
  ./runoff Alice Bob Charlie
  Number of voters: 5
  Rank 1: Alice
  Rank 2: Charlie
  Rank 3: Bob

  Rank 1: Alice
  Rank 2: Charlie
  Rank 3: Bob

  Rank 1: Bob
  Rank 2: Charlie
  Rank 3: Alice

  Rank 1: Bob
  Rank 2: Charlie
  Rank 3: Alice

  Rank 1: Charlie
  Rank 2: Alice
  Rank 3: Bob
  
  Alice

In this example, the user is required to provide a list of candidates as command-line arguments. They are then prompted for the number of voters, and finally where they provide the preferences of each voter. Becuase Alice and Bob would be tied for first, Charlie is then 'eliminated,' and the fifth voter's vote now becomes Alice (their secondn rank), so Alice therefore wins the election.
```

Note: I spent a good amount of time just analyzing this problem before I actually started coding. Much of the code was already provided, and as the instructions explained, I only had to complete those specific functions. This made the problem much more difficult, as I was writing off of 'someone else's' code. I wrote the entire program in one go, and then spent most of the time debugging. I could't even get a remotely close answer during this time. I began changing my code on a smaller scale, altering many small things, and all of a sudden everything worked perfectly. I don't even know what the logical error was, probably some mistype or something like that.

Link: https://cs50.harvard.edu/x/2020/psets/3/runoff/

NOTE: TIDEMAN WAS A FAILED ATTEMPT!!!!!!!!!!!
