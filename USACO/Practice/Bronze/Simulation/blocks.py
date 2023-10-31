import sys
from collections import defaultdict

sys.stdin = open('./blocks.in', 'r')
sys.stdout = open('./blocks.out', 'w')

pairs = []
maxes = {char: 0 for char in "abcdefghijklmnopqrstuvwxyz"}

for _ in range(int(input())):
	pairs.append(tuple(input().split()))

for w1, w2 in pairs:
	counts_1 = defaultdict(lambda: 0)
	counts_2 = defaultdict(lambda: 0)
	
	for letter in w1:
		counts_1[letter] += 1
	for letter in w2:
		counts_2[letter] += 1
	
	for key in maxes.keys():
		maxes[key] += max(counts_1[key], counts_2[key])


ans = ""
for val in maxes.values():
	ans += str(val) + "\n"

print(ans[:-1:], end = "")