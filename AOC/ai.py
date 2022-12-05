from typing import List

def find_top_3_sums(data):
    # split the input string into a list of lines
    lines = data.strip().split('\n\n')

    # create an empty list to store the sums
    sums = []

    # iterate over the lines
    for line in lines:
        # split the line into a list of integers
        nums = [int(n) for n in line.split()]

        # compute the sum of the numbers and add it to the list of sums
        sums.append(sum(nums))

    # sort the list of sums in descending order
    sums.sort(reverse=True)

    # return the first 3 elements of the sorted list of sums
    return sums[:3]

# open the file and read the data
with open('input.txt', 'r') as f:
    data = f.read()

# find the top 3 sums
top_3_sums = find_top_3_sums(data)

# print the top 3 sums
print(top_3_sums)
