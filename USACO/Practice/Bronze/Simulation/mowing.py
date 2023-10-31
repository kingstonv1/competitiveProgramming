# basically the intended solution, except with a huge list. lol

import sys

sys.stdin = open('./mowing.in', 'r')
sys.stdout = open('./mowing.out', 'w')

moves = []

for _ in range(int(input())):
	inp = input().split()
	moves.append((inp[0], int(inp[1])))
	
grid = [[float('inf') for i in range(-100 * 10 + 1, 100 * 10 + 1)] for x in range(-100 * 10 + 1, 100 * 10 + 1)]
grid[0][0] = 0

x, y = 0, 0
time = 0
m = float('inf')

for move in moves:
	xa = 0
	ya = 0
	
	if move[0] == 'N':
		ya = 1
	elif move[0] == 'S':
		ya = -1
	elif move[0] == 'W':
		xa = -1
	elif move[0] == 'E':
		xa = 1
		
	for _ in range(move[1]):
		x += xa
		y += ya
		time += 1
		
		if grid[x][y] == float('inf'):
			grid[x][y] = time
			continue
		else:
			m = min(time - grid[x][y], m)
			grid[x][y] = time


print(-1 if m == float('inf') else m, end = "")
