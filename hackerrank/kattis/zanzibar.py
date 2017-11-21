#!/usr/bin/python3

T = int(input())
for t in range(T):
    t_pop = [int(x) for x in input().split()][:-1]
    lower_bound = 0
    for i, p in enumerate(t_pop[:-1]):
        if t_pop[i+1] > p*2:
            lower_bound += t_pop[i+1] - p*2

    print(lower_bound)
