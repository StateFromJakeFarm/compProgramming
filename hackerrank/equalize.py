#!/usr/bin/python3
import operator

n = int(input())
A = [int(x) for x in input().split()]

d = {}
for a in A:
    if a not in d:
        d[a] = 1
    else:
        d[a] += 1

most = 0
for i in d.keys():
    if d[i] > most:
        most = d[i]

print(n-most)
