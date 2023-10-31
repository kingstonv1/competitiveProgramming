import sys

sys.stdin = open('./shuffle.in', 'r')
sys.stdout = open('./shuffle.out', 'w')

input()

shuffle = list(map(int, input().split()))
cows = list(map(int, input().split()))

temp = [0 for _ in range(len(cows))]

for _ in range(3):
	for i in range(len(shuffle)):
		temp[i] = cows[shuffle[i] - 1]
	
	cows = temp
	temp = [0 for _ in range(len(cows))]


print("\n".join([str(i) for i in cows]), end = "")