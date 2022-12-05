ab = [int(x) for x in input().split()]
a = ab[0]
b = ab[1]
sum = 0

for i in range (a, (b + 1)):
    sum = sum + (i * i)
print(sum)