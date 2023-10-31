n = int(input())
nums = set(map(int, input().split()))
allNums = set([x for x in range(1, n + 1)])
print(list(allNums.difference(nums))[0])
