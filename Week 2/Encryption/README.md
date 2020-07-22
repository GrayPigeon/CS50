**Caesar Cipher (Easier Assignment)**

Instructions (paraphrased): 
1. Accept a single command-line argument, a non-negative integer. Let’s call it k for the sake of discussion. 
2. Output plaintext: (without a newline) and then prompt the user for a string of plaintext.
3. Output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters should be outputted unchanged.
4. Preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
5. Properly handle unexpected inputs

```
Example: 

  $ ./caesar 1
  plaintext:  hello
  ciphertext: ifmmp
  

In this example, the user requested that the program shifts all of the characters of 'hello' one letter 
forward, resulting in the output 'ifmmp.'
```

Link: https://cs50.harvard.edu/x/2020/psets/2/caesar/

Note: At its core, this program is very basic, and relatively easy. I spent much less time writing the code than I did debugging one or two parts of it, namely handling unexpected inputs. It took me no more than a day to complete this program, and I managed to fix the final bug just before I was about to go to sleep.

*** 

**Substitution (Harder Assignment)**

Instructions (paraphrased): 
1. Your program must accept a single command-line argument, the key to use for the substitution.
2. Output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
3. Output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
4. Preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
5. Properly handle unexpected inputs

```
Example: 

  $ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
  plaintext:  hello, world
  ciphertext: jrssb, ybwsp
  
In this example, the user inputs a new alphabet as a command-line argument. The same index of each letter from the original 
alphabet is then used for the new alphabet. Here, the letter 'a' would be encrypted as the letter 'v', because they both have 
the index of 0.
````

Link: https://cs50.harvard.edu/x/2020/psets/2/substitution/

Note: To achieve basic functionality, I found this program to be far easier than the previous. But once again, I spent probably aruond 80% of the time debugging parts of the code involving handling unexpected inputs. I spent some hours on one bug, and I finally relented, after a days' worth of work to searching up my specific bug. I found a solution which involved manually terminating an array with '\0' at the end (terminating character). I definetly would not have come up with this solution on my own, so I do not think I 'gave up too early' or anything like that.
