#!/usr/bin/python3

from math import factorial

n = int(input())
if n == 0 or n == 1:
    print(0)
else:
    t = 0
    for r in range(2, n+1):
        t += factorial(n) / ( factorial(r) * factorial(n - r) )
    print(int(t))
