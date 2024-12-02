num_cows, num_canes = map(int, input().split())
cows = list(map(int, input().split()))
canes = list(map(int, input().split()))


for x in range(num_canes):
    eaten = 0
    cane = canes[x]

    for i in range(len(cows)): 
        if eaten == cane:
            break
        if cows[i] < eaten:
            continue

        temp = eaten
        eaten = min(cows[i], cane)
        cows[i] += eaten - temp

print('\n'.join(list(map(str, cows))))
