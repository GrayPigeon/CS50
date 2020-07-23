**Readability**

Instructions (paraphrased): 
1. Count the number of letters, words, and sentences in the text input. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
2. Print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
3. If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

```
Example: 

  Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays
  more than any other time of year. For another, he really wanted to do his homework, but was forced to
  do it in secret, in the dead of the night. And he also happened to be a wizard.
  
  Output: Grade 5
  
In this example, the user inputs a text and using the Coleman-Liau formula, the program returns the grade level of this text.
```

Note: I found this program to be relatively simple. I did have some trouble with the formula though, but overall pretty straight-forward.
