import sys, re

count = 0

pointvals = {
    "X": 1,
    "Y": 2,
    "Z": 3,
    "W": 6,
    "D": 3,
    "L": 0
}
c = {
    "AX": "Z",
    "AY": "X",
    "AZ": "Y",
    "BX": "X",
    "BY": "Y",
    "BZ": "Z",
    "CX": "Y",
    "CY": "Z",
    "CZ": "X"
}
w = {
    "X": 0,
    "Y": 3,
    "Z": 6
}

def calc(x, y):
    if (x == "A" and y == "X") or (x == "B" and y == "Y") or (x == "C" and y == "Z"):
        return pointvals["D"]
    if (x == "A" and y == "Z") or (x == "B" and y == "X") or (x == "C" and y == "Y"):
        return pointvals["L"]
    if (x == "A" and y == "Y") or (x == "B" and y == "Z") or (x == "C" and y == "X"):
        return pointvals["W"]
    else:
        print("you're bad lol")

for line in sys.stdin:
    if re.search("END", line):
        break

    s = line.split()
    x, y = s[0], s[1]
    count += w[y]
    count += pointvals[c[x + y]]
print(count)