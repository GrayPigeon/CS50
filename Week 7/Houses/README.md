**Houses**

Instuctions for ```import.py``` (paraphrased)
1. Accept the name of a CSV file as a command-line argument.
2. If the incorrect number of command-line arguments are provided, your program should print an error and exit.
3. You may assume that the CSV file will exist, and will have columns name, house, and birth.
4. For each student in the CSV file, insert the student into the students table in the students.db database.
5. While the CSV file provided to you has just a name column, the database has separate columns for first, middle, and last names. You’ll thus want to first parse each name and separate it into first, middle, and last names. You may assume that each person’s name field will contain either two space-separated names (a first and last name) or three space-separated names (a first, middle, and last name). For students without a middle name, you should leave their middle name field as NULL in the table.

Instructions for ```roster.py``` (paraphrased)
1. Accept the name of a house as a command-line argument.
2. If the incorrect number of command-line arguments are provided, your program should print an error and exit.
3. Query the students table in the students.db database for all of the students in the specified house.
4. Print out each student’s full name and birth year (formatted as, e.g., Harry James Potter, born 1980 or Luna Lovegood, born 1981).
6. Each student should be printed on their own line.
7. Students should be ordered by last name. For students with the same last name, they should be ordered by first name.
Walkthrough

Note: I enjoyed this assignment much more than the ```movies```, for the sole reason that I was writing so few queries. However, this introduction to databases is actually very good and very necessary, as much as I resent(ed) it. 
