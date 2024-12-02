n, m = map(int, input().split())
tunnels = []

for i in range(m):
    tunnels.append(tuple(map(int, input().split())))

print(tunnels)
