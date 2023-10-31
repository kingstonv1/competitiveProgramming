# I felt REALLY dumb when I realized how easy this problem was lmaooo

game = input()
tens = False
a = 0
b = 0

for i in range(0, len(game), 2):
	if game[i] == 'A':
		a += int(game[i + 1])
	else:
		b += int(game[i + 1])

print('A' if a > b else 'B')

# There was also an even easier solution: Just print the last person to score
# print(input()[-2])
