**Cash (Easier Assignment)**

Instructions (paraphrased): 
  1. Implement a program that first asks the user how much change is owed.
  2. Print the minimum number of coins with which that change can be made.
  3. If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
  
    Example: 

    Change owed: 0.41
    Minimum number of coins: 4
    
    In this example, change can be made using the least amount of coins by using one quarter, one dime, one nickel, and one penny.
  
  
  Link: https://cs50.harvard.edu/x/2020/psets/1/cash/

*** 

**Credit (Harder Assignment)***

Instructions (paraphrased): 
- Take input of a credit-card number from the user

Use Luhn's Algorithm to determine if the credit card number is valid, and what type of card it is: 
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number might be valid.
4. If Step 3's condition is satisfied, a number is valid if they are either an American Express Card (15-digit number), a MasterCard(16-digit number), or a VISA (13 or 16 digit number). Furthermore, American Express numbers must (in addition to having a length of 15-digits) start with the numbers 34 of 37. MasterCards (in addition to having a length of 16-digits) must start with either 51, 52, 53, 54, or 55. VISA cards (in addition to having a length of either 13 or 16) must start with 4. 
5. If the requirements in either Step 3 or Step 4 are not met, the number is not valid. 


Note: Check the link for a more detailed explanation on CS50's website

Link: https://cs50.harvard.edu/x/2020/psets/1/credit/#luhns-algorithm

***

I was able to do the 'Cash' assignment relatively quickly. The 'Credit' assignment, however, took me an entire day to complete. I had to think of some really complex 'formula' to simply aquire each individual digit of the number! (Because CS50 has not taught arrays and stuff like that yet.) I found this assignment to be incredibly challenging, but also very enjoyable. 'Cash' and 'Credit' should not even be in the same README as there is such a massive 'difficulty gap' tbh.
