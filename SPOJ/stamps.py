for x in range (int(input())):
    s = input().split()
    targ = int(s[0])
    frs = int(s[1])
    stamps = []
    total = 0
    
    inv = input().split()
    
    for i in inv:
        stamps.append(int(i))
    
    stamps.sort(reverse=True)
    
    print("Scenario #" + str(x + 1))
    
    for i in range (frs):
        total += stamps[i]
        if (total >= targ):
            print(i + 1)
            break
        if (i == (frs - 1)):
            print("impossible")
    print()