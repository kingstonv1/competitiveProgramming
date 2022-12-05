import sys

count = 0

for line in sys.stdin:
    if line == "END":
        break
    
    s = line.split(",")
    range1, range2 = s[0], s[1]
    st = range1.split("-")
    st2 = range2.split("-")
    elf1, elf2, elf3, elf4 = int(st[0]), int(st[1]), int(st2[0]), int(st2[1])
    
    for i in range(elf1, elf2 + 1):
        if i in range(elf3, elf4 + 1):
            count += 1
            break
print(count)