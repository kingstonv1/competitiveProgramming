nums = []
for _ in range (int(input())):
    nums.append(int(input()))
nums.sort()
nums = [*set(nums)]
for i in nums:
    print(i)