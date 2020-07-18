**Easier Assignment**

Instructions (paraphrased): 
  1. Prompt the user for a height between (and including) 1 and 8. If the input is not as expected, re-prompt the user.
  2. Create a right-justified staircase of hashes (#) that is the height of the user's input.


Example: 

  Height: 6
  
  Output:
  
         #
        ##
       ###
      ####
     #####
    ######


Link: https://cs50.harvard.edu/x/2020/psets/1/mario/less/
  
  ***
  
**Harder Assignment**
  
Instructions (paraphrased): 
  1. Prompt the user for a height between (and including) 1 and 8. If the input is not as expected, re-prompt the user.
  2. Create a pyramid of hashes (#) where there is a two-space gap in the middle, that is the height of the user's input.
  
  Example: 
    
    Height: 6
    
    Output: 
           #  #
          ##  ##
         ###  ###
        ####  ####
       #####  #####
      ######  ######
      
 Link: https://cs50.harvard.edu/x/2020/psets/1/mario/more/
 
 ***
      
Note: These programs were created after learning less than two hours' worth of C, so parts of the code are probably pretty bad. Most notably, I initialized the 'hash' array and 'spaces' array with a length of 1024, which physically hurt me. We did not even learn about arrays at this point, and from my understanding, dynamic array lengths are not a thing in C, and some other more 'advanced' processes would need to be done to allocate for this.
