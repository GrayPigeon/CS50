import sys
from cs50 import SQL


def main():
    # Check for (im)proper amount command-line arguments
    if (len(sys.argv) != 2):
        print("ERROR")
        return

    # Databas
    db = SQL("sqlite:///students.db")

    # Query to select all students of the specified house
    students = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first;", sys.argv[1])

    # Loop through the 'students' list of dictionaries
    for i in range(len(students)):
        # Retrieve the needed values
        first = students[i].get('first') + " "

        if students[i].get('middle') is None:
            middle = ""
        else:
            middle = students[i].get('middle') + " "

        last = students[i].get('last')
        born = ", " + str(students[i].get('birth'))

        # Print the results
        print(first, middle, last, born, sep='')


main()
