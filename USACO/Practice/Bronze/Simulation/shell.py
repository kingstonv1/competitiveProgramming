import sys

sys.stdin = open('./shell.in', 'r')
sys.stdout = open('./shell.out', 'w')

game = []

for _ in range(int(input())):
	game.append(list(map(int, input().split())))

max_points = 0

for i in range(1, 4):
	p = i
	pts = 0
	
	for move in game:
		if move[0] == p or move[1] == p:
			p = move[1] if p == move[0] else move[0]
		
		if move[2] == p:
			pts += 1
	
	max_points = max(pts, max_points)
	
print(max_points, end = "")