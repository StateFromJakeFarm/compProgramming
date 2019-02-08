t = int(input())
for _ in range(t):
    n, m, s = [int(v) for v in input().split(' ')]
    m -= 1
    mod = m % n
    if mod == 0:
        print(s)
    elif s + mod > n:
        print(s + mod - n)
    else:
        print(s + mod)
