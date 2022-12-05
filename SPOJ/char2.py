for _ in range (int(input())):
    rc = input().split()
    row = int(rc[0])
    col = int(rc[1])
    
    for r in range (row):
        for c in range (col):
            if r == 0 or r == (row - 1):
                print("*", end = "")
            elif (c == 0 or c == (col - 1)):
                print("*", end = "")
            else:
                print(".", end = "")
        print()
    print()