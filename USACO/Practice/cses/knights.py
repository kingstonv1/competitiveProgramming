i = int(input())


for n in range(1, i + 1):
	configurations = (n ** 2 * (n ** 2 - 1)) // 2
	attackingConfigurations = 4 * (n - 1) * (n - 2)
	
	print(configurations - attackingConfigurations)
