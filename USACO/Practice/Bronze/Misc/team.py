count = 0

for _ in range(int(input())):
	count += 1 if (sum(list(map(int, input().split()))) >= 2) else 0
	
print(count)