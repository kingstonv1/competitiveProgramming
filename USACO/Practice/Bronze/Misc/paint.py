# This one's solution was slightly more complicated than I thought at first. Just use a set.

inp = open('paint.in', 'r')
output = open('paint.out', 'w')

i = inp.readlines()
a, b = tuple(map(int, i[0].split()))
c, d = tuple(map(int, i[1].split()))
painted = set()

for x in range(a, b):
	painted.add(x)

for x in range(c, d):
	painted.add(x)

output.write(str(len(painted)))
