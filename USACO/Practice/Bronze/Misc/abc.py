nums = list(map(int, input().split()))
abc = None

biggest = nums.pop(nums.index(max(nums)))

for x in nums:
	for y in nums:
		for z in nums:
			if x + y + z == biggest:
				abc = [x, y, z]

abc.sort()
print(*abc)
