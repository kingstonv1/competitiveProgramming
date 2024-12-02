import math
import sys

input()
cows = input()

m = float('inf')
temp = 0

for num in cows:
    if num == '0' and temp != 0:
        m = min(temp, m)
        temp = 0
    else:
        temp += 1

m = min(temp, m)

if m == 1 or m == float('inf') or len(cows) == 1:
    print(cows.count('1'))
    sys.exit()

days = (m - 1) / 2


