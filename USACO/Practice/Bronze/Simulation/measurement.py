import sys

sys.stdin = open('./measurement.in', 'r')
sys.stdout = open('./measurement.out', 'w')

cows = {"M": 7, "E": 7, "B": 7}
yesterday = {'M': 7, 'E': 7, 'B': 7}
days = [tuple() for _ in range(101)]
display = [name for name in cows.keys()]
count = 0

for _ in range(int(input())):
	inp = input().split()
	days[int(inp[0])] = (inp[1], int(inp[2]))
	
for day in days:
	if day == tuple():
		continue
	
	cows[day[0][0]] += day[1]
	m = max(cows.values())
	new_display = [name for name in cows.keys() if cows[name] == m]

	if new_display != display:
		count += 1
		display = new_display
	
	

print(count, end = "")
