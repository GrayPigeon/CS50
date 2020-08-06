**Speller**

Instructions (paraphrased): 
  1. Implement a program that spell-checks a file according to a dictionary
  
[Detailed Instructions Here](https://cs50.harvard.edu/x/2020/psets/5/speller/)

Note: 

TL;DR: My program leaked some memory, so my final score on this program was a 91%, but they were just valgrind errors, and not logical/syntactical errors

I have a lot I want to talk about. As I was writing this program and each function that had to be completed, I didn't bother testing stuff on my own, as that was just a giant pain to do. So when I finished writing the program, I kind of just crossed my fingers and hoped it had worked. Normally, I would've checked things as I went along, but as I said this one was very annoying to check. So when I did Check50, things unsurprisingly didn't work the first time. In fact, my program didn't even output anything, just an empty string, which was very demoralizing. After a couple hours of half-heartedly trying to find the bug, I re-ran my program out of pure hope, and literally everything worked. During those hours of debugging, I was kind of just rewriting some lines of code and hoping that it worked. So my entire program failed probably because of one minor typo, and when I luckily fixed my typo, everything worked. All but one test passed, the memory leakage test, which involved writing a function to free all of the memory used. There were so many leakages and over the course of the next day, I was chipping away at it. I eventually got down to a handful of valgrind messages, which also happened to be the ones that I couldn't have fixed without changing a large amount of my code. I spent a good amount of time trying to fix them, but eventually, I just gave in and submitted what I had. My final score was a 91, which was the first non one-hundred score. Normally I wouldn't except this as I was trying to learn instead of just trying to pass the course, but the 'errors' was just valgrind errors, so I didn't really care, and I wanted to end my C writing career right then and there (this was the last of the psets that involved C).

I can't wait for python
