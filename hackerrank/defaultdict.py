from collections import defaultdict

d = defaultdict(list)

n, m = [int(x) for x in input().split()]

for i in range(n):
    x = str(input())
    d[x].append(i+1)

for i in range(m):
    x = str(input())
    if len(d[x]):
        for j in d[x]:
            print(j, end=' ')
        print()
    else:
        print(-1)
