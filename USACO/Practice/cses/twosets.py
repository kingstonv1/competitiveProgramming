n = int(input())
totalSum = (n * (n + 1) // 2)

if totalSum % 2 != 0:
	print("NO")
	exit()
	
desiredSum = (n * (n + 1) / 2) // 2
firstArr = []
secondArr = []

for i in range(n, 0, -1):
	if i <= desiredSum:
		desiredSum -= i
		firstArr.append(i)
	
	else:
		secondArr.append(i)

print('YES')
print(len(firstArr))
print(*firstArr)
print(len(secondArr))
print(*secondArr)
