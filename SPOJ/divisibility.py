for _ in range (int(input())):
    nums = input().split()
    n = int(nums[0])
    x = int(nums[1])
    y = int(nums[2])
    
    for i in range (n):
        if i % x == 0 and i % y != 0:
            print(i, end = " ")
    print()