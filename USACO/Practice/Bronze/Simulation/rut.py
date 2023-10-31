cows = []
ecows = []
ncows = []

for _ in range(int(input())):
	inp = input()
	cows.append(inp)
	
	inp = inp.split()
	d, sx, sy = inp[0], int(inp[1]), int(inp[2])
	if d == 'E':
		ecows.append((sx, sy))
	else:
		ncows.append((sx, sy))

ncows.sort()
ecows.sort(key = lambda c: c[1])

for cow in cows:
	cow_min = float('inf')
	t = cow.split()
	
	if cow[0] == 'E':
		compare = ncows
		c1 = 0
		c2 = 1
	else:
		compare = ecows
		c1 = 1
		c2 = 0
	
	cow = (int(t[1]), int(t[2]))
	
	for cow2 in compare:
		if cow[c1] > cow2[c1] or cow2[c2] > cow[c2]:
			continue
		
		diff = cow2[c1] - cow[c1]
		
		if cow[c2] < cow2[c2] + diff:
			cow_min = min(cow_min, diff)
		
	print(cow_min if cow_min != float('inf') else 'Infinity')
	