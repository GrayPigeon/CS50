from cs50 import get_int
from sys import exit

# Credit card number
number = get_int("Number: ")

# Credit card number in a list
numList = []
for i in str(number):
    numList.append(i)

# Determine the parity
if len(numList) % 2 == 0:
    parity = "even"
else:
    parity = "odd"

# Adds together the multiplied sum as a string
multipliedSum = ""

# Doubled number sum
sum = 0

# Not doubled numbers sum
otherParitySum = 0

skip = False

# Each digit
for i in numList:
    # Skip the first digit if odd length
    if parity == "odd":
        otherParitySum += int(i)
        parity = "not"
        continue

    # A way to count every other digit
    if skip:
        otherParitySum += int(i)
        skip = False
        continue

    # Add to multipliedSum string
    multipliedSum += str(int(i) * 2)
    skip = True

# Add each digit of multiplied sum together
for i in multipliedSum:
    sum += int(i)

# Add that to the other digits
sum += otherParitySum

# If the final result is not divisble by 10, it is invalid
if sum % 10 != 0:
    print("INVALID")
    exit(1)

# The paramaters for each type of card
if int(numList[0]) == 3 and len(numList) == 15 and int(numList[1]) == 4 or int(numList[1]) == 7:
    print("AMEX")
elif int(numList[0]) == 5 and int(numList[1]) > 0 and int(numList[1]) < 6 and len(numList) == 16:
    print("MASTERCARD")
elif int(numList[0]) == 4 and len(numList) == 13 or len(numList) == 16:
    print("VISA")
else:
    print("INVALID")
