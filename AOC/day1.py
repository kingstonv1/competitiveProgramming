from sys import stdin
import time

elves = []
elf = []

lastIndex = 0
lastIndex2 = 0

most = 0
most2 = 0
most3 = 0

for line in stdin:
    if line == "end\n":
        break
    if line == "\n":
        elves.append(elf)
        elf = []
    else:
        elf.append(line[:-1])

print(elves)

for i in range (len(elves)):
    if sum(int(x) for x in elves[i]) > most:
        most = sum(int(x) for x in elves[i])
        lastIndex = i

for i in range (len(elves)):
    if i != lastIndex:
        if sum(int(x) for x in elves[i]) > most2:
            most2 = sum(int(x) for x in elves[i])
            lastIndex2 = i

for i in range (len(elves)):
    if i != lastIndex and i != lastIndex2:
        if sum(int(x) for x in elves[i]) > most3:
            most3 = sum(int(x) for x in elves[i])

print(most + most2 + most3)
