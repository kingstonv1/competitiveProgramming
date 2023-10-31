import re


def solve(s, w):
    count = 0

    ind = w.find("our")

    reg = re.compile(w[:ind] + r'(?:or|our)' + w[ind + 3:])

    for i in s.strip().split():
        if reg.match(i):
            count += 1
    return count


s = str()

for _ in range(int(input())):
    s += input().strip()
    s += " "

for _ in range(int(input())):
    w = input()
    print(solve(s, w))