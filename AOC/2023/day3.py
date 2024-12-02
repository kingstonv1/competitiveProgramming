import sys, math

total = 0
inp = []

letters = [
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
]

def divide_chunks(l, n):
    # looping till length l
    for i in range(0, len(l), n):
        yield l[i:i + n]

for line in sys.stdin:
    inp.append(line[:line.rfind('\n')])
    print(line[:line.rfind('\n')])

i = list(divide_chunks(inp, 3))

for x in i:
    for let in letters:
        if x[0].find(let) != -1 and x[1].find(let) != -1 and x[2].find(let) != -1:
            print("letter found: " + let)
            total += (letters.index(let) + 1)

print(total)