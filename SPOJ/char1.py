# your code goes here
for _ in range (int(input())):
	rc = input()
	row = int(rc.split()[0])
	col = int(rc.split()[1])
	
	for r in range (row):
		if r % 2 == 0:
			for c in range (col):
				if c % 2 == 0:
					print("*", end = "")
				else:
					print(".", end = "")
		else:
			for c in range (col):
				if c % 2 == 0:
					print(".", end = "")
				else:
					print("*", end = "")
		print()
	print()