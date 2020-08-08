from cs50 import get_string

# Text from user
text = get_string("Text: ")

# All variables
wordCount = 1
letCount = 0
sentCount = 0


for i in text:
    # If there is a space, add to the word count (which was initialize to one to account for the last word that is not followed by a space)
    if i == " ":
        wordCount += 1
        continue

    # Add to the sentence counter if these symbols appear
    if i == "." or i == "?" or i == "!":
        sentCount += 1
        continue

    # If the letter is in the alphabet
    if i.isalpha():
        letCount += 1

# Grade formula
grade = 0.0588 * (letCount / wordCount * 100) - 0.296 * (sentCount / wordCount * 100) - 15.8

# Extra assignment paramaters
if grade < 1:
    print("Before Grade 1")
elif grade > 15:
    print("Grade 16+")
else:
    print("Grade", round(grade))
