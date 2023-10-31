n = int(input())
nums = [n]

while nums[-1] != 1:
	if nums[-1] % 2 == 0:
		nums.append(nums[-1] // 2)
		continue
	else:
		nums.append(nums[-1] * 3 + 1)

print(' '.join(list(map(str, nums))))
