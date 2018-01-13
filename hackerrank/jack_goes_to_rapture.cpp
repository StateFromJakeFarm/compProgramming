#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct edge {
    int node;
    int weight;
};

typedef vector< vector<edge> > graph;

graph Prims(const graph & G) {
    graph MST( G.size() );

    vector<int> Q;
    vector<int> dists;
    Q.push_back(0);
    dists.push_back(0);
    while (Q.size() > 0) {
        // Extract minimum element
        auto uIter = min_element(dists.begin(), dists.end());
        int u = *uIter;
        Q.erase(uIter);
        dists.erase(uIter);

        for (int i=0; i<G[u].size(); i++) {
            
        }
    }

    return MST;
}

int main() {
    // Construct graph from input
    int N;
    cin >> N;
    graph G(N);

    int E;
    cin >> E;
    int u, v, w;
    for (int e=0; e<E; e++) {
        cin >> u >> v >> w;

        edge uTov, vTou;
        uTov.node = v-1;
        vTou.node = u-1;
        uTov.weight = vTou.weight = w;

        G[u-1].push_back(uTov);
        G[v-1].push_back(vTou);
    }

    graph MST = Prims(G);

    return 0;
}
