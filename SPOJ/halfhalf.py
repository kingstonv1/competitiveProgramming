import math
for _ in range (int(input())):
    s = input()
    s = s[:math.floor((len(s) / 2))]
    for i in range (len(s)):
        if i % 2 == 0:
            print(s[i], end = "")
    print()