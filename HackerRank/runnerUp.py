if __name__ == '__main__':
    input()
    a = list(map(int, input().split()))
    a.sort()
    print(list(set(a))[-2])
