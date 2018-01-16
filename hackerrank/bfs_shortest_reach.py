#!/usr/bin/python3

class Graph:
    class Node:
        def __init__(self):
            self.edges = []

    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.nodes = [Graph.Node() for x in range(self.num_nodes)]

    def add_edge(self, node1, node2):
        self.nodes[node1].edges.append(node2)
        self.nodes[node2].edges.append(node1)

    def get_edges(self, node):
        return [adj for adj in self.nodes[node].edges]

    def dfs_distances(self, s):
        states    = ['w' for x in range(self.num_nodes)]
        distances = [0 for x in range(self.num_nodes)]

        Q = [s]
        distances[s] = 0
        while len(Q) > 0:
            u = Q.pop(0)
            for v in self.get_edges(u):
                if states[v] == 'w':
                    states[v] = 'g'
                    Q.append(v)
                    distances[v] = distances[u] + 1

            states[u] = 'b'

        return distances

queries = int(input())
for q in range(queries):
    n, m = [int(x) for x in input().split()]

    G = Graph(n)
    for edge in range(m):
        u, v = [int(x)-1 for x in input().split()]
        G.add_edge(u, v)

    s = int(input())-1
    for i, dist in enumerate(G.dfs_distances(s)):
        if i != s:
            if dist == 0:
                print(-1, end=' ')
            else:
                print(dist*6, end=' ')
    print()
