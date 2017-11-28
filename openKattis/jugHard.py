#!/usr/bin/python3

T = int(input())
for t in range(T):
    a, b, d = [int(x) for x in input().split(' ')]

    big = max(a, b)
    small = min(a, b)

    if small <= d and d % small == 0:
        print('Yes')
    elif small > d and big - small == d:
        print('Yes')
    elif big - small > 0 and d/(big - small)*1.0 == 2:
        print('Yes')
    else:
        print('No')
