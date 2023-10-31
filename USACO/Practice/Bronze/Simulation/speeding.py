import sys

sys.stdin = open('speeding.in', 'r')
sys.stdout = open('speeding.out', 'w')

n, m = map(int, input().split())

bessie = [0 for _ in range(100)]
road = [0 for _ in range(100)]

bc = 0
for _ in range(n):
	miles, speed = map(int, input().split())
	
	for i in range(bc, bc + miles):
		bessie[i] = speed
	
	bc += miles

bc = 0
for _ in range(m):
	miles, speed = map(int, input().split())
	
	for i in range(bc, bc + miles):
		road[i] = speed
	
	bc += miles

m = 0

for i in range(100):
	m = max((road[i] - bessie[i]), m)
	
print(m, end = "")
