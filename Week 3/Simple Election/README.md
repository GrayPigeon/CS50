**Plurality**

Instructions (paraphrased): 
1. Complete the vote function.
    - Vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
    - If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The vote function in this case should return true to indicate a successful ballot.
    - If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote function should return false to indicate an invalid ballot.
    - You may assume that no two candidates will have the same name.
    
2. Complete the print_winner function.
    - The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
    - It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.

```
Example: 
  $ ./plurality Alice Bob
  Number of voters: 3
  Vote: Alice
  Vote: Bob
  Vote: Alice
  Alice

In this example, the user provided two command-line arguments, which represent the two candidates. They then input the number
of voters and each voter's vote, for the program to then output the winner
```

Note: This program took me probably around a half hour, as 90% of the code was already written, and the assignment just involved relatively basic code, and I assume the next two assignments will prove to be more challenging.
