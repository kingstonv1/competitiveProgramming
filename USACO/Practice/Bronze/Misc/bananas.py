k, n, w = tuple(map(int, input().split()))
totalCost = (w * (w + 1) // 2) * k

if totalCost - n >= 0:
	print(totalCost - n)
else:
	print(0)
