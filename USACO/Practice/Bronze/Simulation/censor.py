import sys

sys.stdin = open('./censor.in', 'r')
sys.stdout = open('./censor.out', 'w')

full = list(input())
c = input()

cur = ''

for char in full:
	cur += char
	
	if len(cur) >= len(c) and cur[-len(c):] == c:
		cur = cur[:-len(c)]
	
print(cur, end = "")
