n = int(input())

if n == 1:
    print(1)
elif n <= 3:
    print("NO SOLUTION")
elif n == 4:
    print("3 1 4 2")
else:
    beautiful_permutation = [0] * n
    i = 0
    for x in range(n, 0, -2):
        beautiful_permutation[i] = x
        i += 1
    for x in range(n-1, 0, -2):
        beautiful_permutation[i] = x
        i += 1
    print(*beautiful_permutation)