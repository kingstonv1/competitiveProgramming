import sys

sys.stdin = open('./mixmilk.in', 'r')
sys.stdout = open('./mixmilk.out', 'w')

buckets = []

for _ in range(3):
	buckets.append(list(map(int, input().split())))

for i in range(100):
	b1 = i % 3
	b2 = (i + 1) % 3
	
	amt = min(buckets[b1][1], (buckets[b2][0] - buckets[b2][1]))
	
	buckets[b1][1] -= amt
	buckets[b2][1] += amt

print("\n".join(str(x[1]) for x in buckets), end = "")