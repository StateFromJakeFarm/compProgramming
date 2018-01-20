#include <iostream>
#include <vector>

using namespace std;

typedef vector<long> vl;
typedef vector<vl> graph;

void add_edge(graph & G, long u, long v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

long dfs_visit(graph & G, vl & visited, long s) {
    visited[s] = 1;

    long cost = 0;

    long neighbor;
    for (long i=0; i<(long)G[s].size(); i++) {
        neighbor = G[s][i];
        if (visited[neighbor] == 0) {
            cost++;
            cost += dfs_visit(G, visited, neighbor);
        }
    }

    return cost;
}

int main() {
    long Q;
    cin >> Q;

    for (long q=0; q<Q; q++) {

        long n, m, cost_lib, cost_road;
        cin >> n >> m >> cost_lib >> cost_road;

        vl visited(n);
        graph G(n);
        long u, v;
        for (long i=0; i<m; i++) {
            cin >> u >> v;
            add_edge(G, u-1, v-1);
        }

        if (m == 0 || cost_lib <= cost_road) {
            cout << cost_lib * n << endl;
            continue;
        }

        long cost = 0;
        for (long i=0; i<n; i++) {
            if (visited[i] == 0) {
                cost += dfs_visit(G, visited, i) * cost_road;
                cost += cost_lib;
            }
        }

        cout << cost << endl;

    }

    return 0;
}
