# This one was hard. Had to watch a breakdown video, made a lot more sense.

def solve(y, x):
	m = max(x, y)
	base = m ** 2
	
	if m % 2 == 0:
		if x != m:
			return base - (x - 1)
		else:
			return base - ((m - 1) + (m - y))
	else:
		if x != m:
			return base - ((m - 1) + (m - x))
		else:
			return base - (y - 1)

for _ in range(int(input())):
	yCoord, xCoord = tuple(map(int, input().split()))
	print(solve(yCoord, xCoord))