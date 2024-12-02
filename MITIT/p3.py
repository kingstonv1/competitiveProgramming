import math

def solve(num):
    for i in range(2, math.isqrt(num)):
        if num % i == 0:
            print(f'{num} {i}')
            return True

    return False

for _ in range(int(input())):
    i = input()

    if solve(int(i)): continue

    for idx in range(len(i)):
        num = int(i[:idx] + i[idx + 1:])
        if solve(num): break
