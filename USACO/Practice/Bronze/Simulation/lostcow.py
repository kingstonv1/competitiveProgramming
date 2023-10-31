import sys

sys.stdin = open('./lostcow.in', 'r')
sys.stdout = open('./lostcow.out', 'w')

x, y = map(int, input().split())

dist = 0
i = 1
pos = x

for _ in range(1001):
	if x < y <= x + i or x > y >= x + i:
		dist += abs(pos - y)
		break
	
	dist += abs((x + i) - pos)
	pos = x + i
	i *= -2


print(dist, end = "")