for _ in range (int(input())):
    n = input()
    t = 0
    for i in range (len(n)):
        t += int(n[i])
    print(t)    