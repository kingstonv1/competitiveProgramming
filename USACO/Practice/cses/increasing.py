input()
count = 0
arr = list(map(int, input().split()))

for i in range(1, len(arr)):
	if arr[i] < arr[i - 1]:
		diff = arr[i - 1] - arr[i]
		count += diff
		arr[i] += diff
	
print(count)