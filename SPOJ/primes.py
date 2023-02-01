# Timelimit :((
def primes(low, high):
    prime = [True for i in range(high + 1)]

    p = 2
    while p * p <= high:
        if prime[p]:
            for i in range(p * p, high + 1, p):
                prime[i] = False
        p += 1

    for p in range(2, high + 1):
        if prime[p]:
            print(p)


for _ in range(int(input())):
    nums = list(map(int, input().split()))
    primes(nums[0], nums[1])
