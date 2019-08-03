#!/usr/bin/python3

from operator import add

q = int(input())

for _ in range(q):
    n = int(input())
    M = [[] for row in range(n)]

    container_quantities = set()
    type_quantities = [0 for t in range(n)]
    for row in M:
        row += [int(t) for t in input().split(' ')]
        container_quantities.add(sum(row))
        type_quantities = list(map(add, type_quantities, row))

    type_quantities = set(type_quantities)

    if container_quantities == type_quantities:
        print('Possible')
    else:
        print('Impossible')
