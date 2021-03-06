#!/usr/bin/python3

import heapq
from sys import maxsize

distances = []

class Graph:
    class Node_and_rank:
        def __init__(self, n):
            self.n = n

        def __lt__(self, other):
            return distances[self.n] < distances[other.n]

    def __init__(self, N):
        self.N = N
        self.Nodes = [{} for n in range(self.N)]

    def add_edge(self, x, y, r):
        if y not in G.Nodes[x] or r < G.Nodes[x][y]:
            G.Nodes[x][y] = r
            G.Nodes[y][x] = r

    def dijkstras(self, S):
        Q = [Graph.Node_and_rank(n) for n in range(self.N)]
        heapq.heapify(Q)

        while len(Q) > 0:
            u = heapq.heappop(Q).n
            for adj in self.Nodes[u].keys():
                if distances[adj] > distances[u] + self.Nodes[u][adj]:
                    distances[adj] = distances[u] + self.Nodes[u][adj]
                    heapq.heapify(Q)

# Number of testcases
T = int(input())
for t in range(T):
    # Number of nodes and edges
    N, M = [int(x) for x in input().split(' ')]

    # Create instance of our graph
    G = Graph(N)

    # Gather all edges
    for m in range(M):
        x, y, r = [int(x) for x in input().split(' ')]
        x -= 1
        y -= 1

        G.add_edge(x, y, r)

    # Starting point of Dijstra's algo
    S = int(input())-1

    # Run Dijkstra's algo to get minimum distances
    distances = [maxsize for n in range(N)]
    distances[S] = 0
    G.dijkstras(S)
    for i, dist in enumerate(distances):
        if i != S:
            if dist == maxsize:
                print(-1, end=' ')
            else:
                print(dist, end=' ')
    print()
