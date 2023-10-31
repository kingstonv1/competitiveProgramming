import sys

sys.stdin = open('./cowsignal.in', 'r')
sys.stdout = open('./cowsignal.out', 'w')

m, n, k = map(int, input().split())

sig = []

for _ in range(m):
	sig.append(input())

final = []

for i in range(len(sig)):
	for _ in range(k):
		line = ""
		
		for char in sig[i]:
			line += char * k
	
		final.append(line)
	
print("\n".join(final), end = "")