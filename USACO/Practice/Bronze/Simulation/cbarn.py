import sys

sys.stdin = open('./cbarn.in', 'r')
sys.stdout = open('./cbarn.out', 'w')

barn = [int(input()) for _ in range(int(input()))]

m = float('inf')
cows = sum(barn)

for o in range(len(barn)):
	cur_dist = 0
	cur_cows = cows
	
	for i in range(o, len(barn) + o):
		cur_cows -= barn[i % len(barn)]
		cur_dist += cur_cows
		
	m = min(m, cur_dist)
	

print(m, end = "")
