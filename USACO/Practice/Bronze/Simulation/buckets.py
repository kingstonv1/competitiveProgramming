import sys

sys.stdin = open('mixmilk.in', 'r')
sys.stdout = open('./buckets.out', 'w')


def solve(barn, rock, lake):
	o = -1
	
	if barn[0] == rock[0] == lake[0] and \
		(lake[1] < rock[1] < barn[1] or lake[1] > rock[1] > barn[1]):
		o = 1

	if barn[1] == rock[1] == lake[1] and \
		(lake[0] < rock[0] < barn[0] or lake[0] > rock[0] > barn [0]):
		o = 1
	
	return (max(barn[0], lake[0]) - min(barn[0], lake[0])) + (max(barn[1], lake[1]) - min(barn[1], lake[1])) + o


b = None
r = None
l = None

for i in range(10):
	line = input()
	
	for z in range(len(line)):
		if line[z] == 'B':
			b = [z, i]
		elif line[z] == 'R':
			r = [z, i]
		elif line[z] == 'L':
			l = [z, i]
	
print(solve(b, r, l), end = "")
	