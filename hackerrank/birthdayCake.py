#!/usr/bin/env python3
c = input()
candles = [int(c) for c in input().split()]

max = 0
numMax = 0
for c in candles:
    if c > max:
        max = c
        numMax = 1
    elif c == max:
        numMax += 1

print(numMax)
