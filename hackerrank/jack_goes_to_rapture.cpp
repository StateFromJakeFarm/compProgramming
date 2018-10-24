#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

typedef vector< vector< pair<int, int> > > Graph;
typedef vector< tuple<int, int, int> > Edges;

int dfs(const Graph &G, const int u, const int p, const int my_cost) {
    if (u == (int)G.size()-1) {
        return my_cost;
    }

    int v, c;
    int max_found = INT_MIN;
    for (int j=0; j<G[u].size(); j++) {
        v = G[u][j].first;
        c = G[u][j].second;

        if (v == p) {
            // Don't revisit parent
            continue;
        }

        int ret = dfs(G, v, u, max(my_cost, c));
        max_found = max(ret, max_found);
    }

    return max_found;
}

// Add edge to the graph
void add_edge(Graph &G, const int &u, const int &v, const int &c) {
    G[u].push_back( make_pair(v, c) );
    G[v].push_back( make_pair(u, c) );
}

// Run path compression and return current parent
int get_root(vector<int> &root, int u) {
    while (root[u] != u) {
        root[u] = root[root[u]];
        u = root[u];
    }

    return u;
}

// Find MST of graph
Graph kruskal(const Graph &G, Edges &edge_weights) {
    // Sort edge weights
    sort(edge_weights.begin(), edge_weights.end());

    // Set root
    vector<int> root(G.size());
    for (int i=0; i<(int)G.size(); i++) {
        root[i] = i;
    }

    // Create MST
    Graph MST(G.size());
    int c, u, v;
    for (auto e : edge_weights) {
        c = get<0>(e);
        u = get<1>(e);
        v = get<2>(e);

        int x, y;
        if (get_root(root, u) != get_root(root, v)) {
            add_edge(MST, u, v, c);

            // Union the trees
            x = get_root(root, u);
            y = get_root(root, v);

            root[x] = root[y];
        }
    }

    return MST;
}

int main() {
    int N, E;
    cin >> N >> E;

    Graph G(N);
    queue<int> q;
    for (int i=0; i<N; i++) {
        q.push(i);
    }

    int u, v, c;
    Edges edge_weights(E);
    for (int i=0; i<E; i++) {
        cin >> u >> v >> c;
        u--; v--;
        add_edge(G, u, v, c);
        edge_weights[i] = make_tuple(c, u, v);
    }

    // Create MST
    Graph MST = kruskal(G, edge_weights);

    // Get heaviest edge on path from stations 1 to N
    int best = dfs(MST, 0, 0, 0);

    if (best == INT_MIN) {
        cout << "NO PATH EXISTS" << endl;
    } else {
        cout << best << endl;
    }

    return 0;
}
