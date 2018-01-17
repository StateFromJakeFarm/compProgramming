#!/usr/bin/python3

import heapq
from sys import maxsize

class Graph:
    class Node_and_rank:
        def __init__(self, n, dist):
            self.n = n
            self.dist = dist

        def set_dist(self, dist):
            self.dist = dist

        def get_dist(self):
            return self.dist

        def __lt__(self, other):
            return self.dist < other.dist

    def __init__(self, N):
        self.N = N
        self.Nodes = [{} for n in range(self.N)]

    def add_edge(self, x, y, r):
        G.Nodes[x][y] = r
        G.Nodes[y][x] = r

    def dijkstras(self, S):
        distances = [maxsize for n in range(self.N)]
        distances[S] = 0

        Q = [Graph.Node_and_rank(n, maxsize) for n in range(self.N)]
        Q[S].set_dist(0)
        heapq.heapify(Q)

        while len(Q) > 0:
            u = heapq.heappop(Q).n
            for adj in self.Nodes[u].keys():
                if distances[adj] > distances[u] + self.Nodes[u][adj]:
                    distances[adj] = distances[u] + self.Nodes[u][adj]

                    for elm in Q:
                        if elm.n == adj:
                            elm.dist = distances[adj]
                            heapq.heapify(Q)
                            break

        return distances

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
    for i, dist in enumerate(G.dijkstras(S)):
        if i != S:
            print(dist, end=' ')
    print()
