import sys
import csv
from cs50 import SQL


def main():
    # Check for (im)proper amount of command-line arguments
    if (len(sys.argv) != 2):
        print("ERROR")
        return

    # People dictionary
    people = {}

    with open(sys.argv[1], 'r') as file:
        # DictReader
        reader = csv.DictReader(file)

        # Loop through each row
        for row in reader:
            values = []

            # Add to values array
            values.append(row['house'])
            values.append(row['birth'])
            people[row['name']] = values

    # Database
    db = SQL("sqlite:///students.db")

    # Loop through people dictionary
    for key in people:
        # Split the name
        nameArr = key.split()

        # If the person has a middle name or not
        # Add to the SQL table
        if (len(nameArr) == 2):
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       nameArr[0], None, nameArr[1], people.get(key)[0], people.get(key)[1])
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       nameArr[0], nameArr[1], nameArr[2], people.get(key)[0], people.get(key)[1])


main()
