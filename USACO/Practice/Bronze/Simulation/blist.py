import sys

sys.stdin = open('./blist.in', 'r')
sys.stdout = open('./blist.out', 'w')

n = int(input())
cows = []

for i in range(n):
	cows.append(tuple(map(int, input().split())))


m = 0
for i in range(1, 1001):
	cur = 0
	
	for t in cows:
		if t[0] <= i <= t[1]:
			cur += t[2]
	
	m = max(cur, m)


print(m, end = "")
