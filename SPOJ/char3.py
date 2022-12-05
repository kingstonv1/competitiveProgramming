for _ in range (int(input())):
    rc = input().split()
    row = int(rc[0])
    col = int(rc[1])
    
    row = (row * 3) + 1
    col = (col * 3) + 1
    
    for r in range (row):
        for c in range (col):
            if r == 0 or r == (row - 1) or r % 3 == 0:
                print("*", end = "")
            elif c == 0 or c == (col - 1) or c % 3 == 0:
                print("*", end = "")
            else:
                print(".", end = "")
        print()
    print()