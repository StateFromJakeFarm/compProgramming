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

void dfs(const Graph &G, vector<int> &max_on_path, const int u) {
    int v;
    int c, max_to_v_from_u;
    for (int j=0; j<G[u].size(); j++) {
        v = G[u][j].first;
        c = G[u][j].second;

        max_to_v_from_u = max(max_on_path[u], c);

        if (max_on_path[v] > max_to_v_from_u) {
            max_on_path[v] = max_to_v_from_u;

            if (v == (int)G.size()-1) {
                // Because this is a tree, we can stop when we hit destination
                return;
            }

            dfs(G, max_on_path, v);
        }
    }
}

// Add edge to the graph
void add_edge(Graph &G, const int &u, const int &v, const int &c) {
    G[u].push_back( make_pair(v, c) );
    G[v].push_back( make_pair(u, c) );
}

// Run path compression and return current parent
int get_parent(const Graph &G, vector<int> &parents, const int &u) {
    int cur = u;
    int prev = cur;
    while (parents[cur] != cur) {
        prev = cur;
        cur = parents[cur];
    }

    parents[u] = cur;

    return cur;
}

// Find MST of graph
Graph kruskal(const Graph &G, Edges &edge_weights) {
    // Sort edge weights
    sort(edge_weights.begin(), edge_weights.end());

    // Set parents
    vector<int> parents(G.size());
    for (int i=0; i<(int)G.size(); i++) {
        parents[i] = i;
    }

    // Create MST
    Graph MST(G.size());
    int c, u, v;
    for (auto e : edge_weights) {
        c = get<0>(e);
        u = get<1>(e);
        v = get<2>(e);

        if (get_parent(G, parents, u) != get_parent(G, parents, v)) {
            add_edge(MST, u, v, c);
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
    vector<int> max_on_path(MST.size(), INT_MAX);
    max_on_path[0] = 0;
    dfs(MST, max_on_path, 0);

    if (max_on_path[N-1] == INT_MAX) {
        cout << "NO PATH EXISTS" << endl;
    } else {
        cout << max_on_path[N-1] << endl;
    }

    return 0;
}
