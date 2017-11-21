#!/usr/bin/python3

v = int(input())
E = [int(e) for e in input()]

if sum(E) > v-1:
    # The most edges we will ever have in a forest of v
    # vertices is v-1
    print('IMPOSSIBLE')
    return


