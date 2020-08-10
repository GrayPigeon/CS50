from sys import argv, exit
import csv

# Check for the appropriate command-line arguments
if len(argv) != 3:
    print("ERROR")
    exit(1)

# Store the files in memory
data = argv[1]
sequence = argv[2]

# CSV file as a dictionary (to be added to)
people = {

}

# Open the CSV file and read it using DictReader
with open(data, 'r') as csvFile:
    reader = csv.DictReader(csvFile)

    # Names to be stored
    names = []
    counter = 0

    # Each row of the CSV file
    for row in reader:
        headers = reader.fieldnames

        # Each name
        names.append(row[headers[0]])
        length = len(headers)

        # Current name
        thisName = names[counter]

        # List of values for each person to be added to the dictionary
        eachValues = []
        each = 1

        # Add to array
        while (each < length):
            eachValues.append(row[headers[each]])
            each += 1

        # Add to the dictionary
        people[names[counter]] = eachValues
        counter += 1

# Open the text file
with open(sequence, "r") as seq:
    # Everything in the file (all in one row)
    seqText = seq.read()

    # The particular DNA bases to be searched
    search = []

    # The 'search' list but the values are the lengths of each 'search' value
    searchLens = []
    counter = 1

    # The frequency of each base in the text file
    result = []

    # Add to the lists
    while counter < length:
        search.append(headers[counter])
        searchLens.append(len(headers[counter]))
        counter += 1

    indexCounter = 0

    # Each base
    for i in range(len(searchLens)):
        # A lot of variables that I forgot about
        tmpK = 0
        shouldBreak = False
        cont = False
        record = 0
        current = 0

        # Each letter in the text
        for k in seqText:
            word = ""

            # Add to the word based on the current length of the bases
            for n in range(searchLens[i]):
                if tmpK + int(n) >= len(seqText):
                    shouldBreak = True
                    break

                word += seqText[tmpK + int(n)]

            if shouldBreak:
                break

            # If there is a match
            if str(word) == str(search[indexCounter]):
                # Some really weird solution for determining if bases are consecutive
                current += 1

                if current > record:
                    record = current

                # print("Current", current)
                # print("Record", record)
                tmpK += len(word)
                cont = True

            else:
                current = 0
                cont = False

                tmpK += 1

        # Add to result the longest sequence of the particular base
        result.append(record)

        indexCounter += 1

# More variables
same = False
found = False

# Cycle throught the dictionary
for q in people:
    resCount = 0

    # Cycle through each array within the dictionary's keys
    for p in people[q]:
        # If it equals the 'result' array
        if str(result[resCount]) == (p):
            same = True
        else:
            same = False
            break
        resCount += 1

    if same:
        found = True
        print(q + ".")

if not found:
    print("No match.")
