promotions = list()
promoCounts = [0, 0, 0]

with open('promote.in', 'r') as inp:
	for _ in range(4):
		promotions.append(list(map(int, inp.readline().strip().split())))
		
promotions.reverse()

promoCounts[2] = promotions[0][1] - promotions[0][0]
promoCounts[1] = promotions[1][1] + promoCounts[2] - promotions[1][0]
promoCounts[0] = promotions[2][1] + promoCounts[1] - promotions[2][0]

# print(*[i for i in promoCounts], sep = '\n')

with open('promote.out', 'w') as output:
	promoCounts = list(map(str, promoCounts))
	output.write('\n'.join(promoCounts))
