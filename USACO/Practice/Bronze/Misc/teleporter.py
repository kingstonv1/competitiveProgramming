with open('teleport.in', 'r') as inp:
	start, end, tp1, tp2 = tuple(map(int, inp.readline().split()))

toTeleporter = min(abs(start - tp1), abs(start - tp2))
finaltpDistance = 0

if toTeleporter == abs(start - tp1):
	finaltpDistance = toTeleporter + abs(end - tp2)
else:
	finaltpDistance = toTeleporter + abs(end - tp1)
	
walkingDistance = abs(start - end)

with open('teleport.out', 'w') as output:
	output.write(str(min(finaltpDistance, walkingDistance)))
