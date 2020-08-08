from cs50 import get_int

while True:
    count = get_int("Count: ")
    if count > 0 and count < 9:
        break

# Prints each line/row
for i in range(count + 1):

    # Skip the first one cus idk how to change 'i' starting value in for loop
    if i == 0:
        continue

    # Print the appropriate spaces and hashes for the left side
    print(" " * (count - i), end="")
    print("#" * i, end="")

    # Print the appropriate spaces and hashes for the right side
    print("  ", end="")
    print("#" * i)
