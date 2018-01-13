#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector< vector< pair<int, int> > > graph;

list< pair<int, int> >::iterator get_min_iter(list< pair<int, int> > & Q) {
    auto min_iter = Q.begin();
    for (auto it=Q.begin(); it!=Q.end(); it++) {
        if (it->second < min_iter->second)
            min_iter = it;
    }

    return min_iter;
}

list< pair<int, int> >::iterator find_in_Q(list< pair<int, int> > & Q, int elm) {
    list< pair<int, int> >::iterator it;
    for (it = Q.begin(); it!=Q.end(); it++) {
        if (it->first == elm)
            return it;
    }

    return it;
}

graph Prims(const graph & G) {
    graph MST( G.size() );

    vector<int> parents;
    list< pair<int, int> > Q;
    for (int i=0; i<G.size(); i++) {
        int weight = INT_MAX;
        int parent = INT_MAX;
        if (i == 0) {
            weight = 0;
            parent = 0;
        }

        parents.push_back(parent);
        Q.push_back( make_pair(i, weight) );
    }

    while (!Q.empty()) {
        // Extract min "rank" (smallest known edge weight)
        auto min_iter = get_min_iter(Q);
        int u = min_iter->first;
        Q.erase(min_iter);

        // Add this edge to our MST
        MST[u].push_back( G[u][ parents[u] ] );
        MST[ parents[u] ].push_back( G[ parents[u] ][u] );
        cout << "adding " << u+1 << " to " << G[u][ parents[u] ].first+1 << " (" << G[u][ parents[u] ].second << ")" << endl;

        // Update for neighbors
        for (int i=0; i<(int)G[u].size(); i++) {
            int v = G[u][i].first;
            auto find_v = find_in_Q(Q, v);
            if (find_v != Q.end() && find_v->second > G[u][i].second) {
                find_v->second = G[u][i].second;
                parents[v] = u;
            }
        }
    }

    return MST;
}

int dfs(const graph & G, int cur_vertex, vector<int> & max_on_path, vector<bool> & visited) {
    cout << cur_vertex << endl;
    visited[cur_vertex] = 1;
    if (cur_vertex == (int)G.size()-1)
        return max_on_path[cur_vertex];

    for (int i=0; i<(int)G[cur_vertex].size(); i++) {
        int v = G[cur_vertex][i].first;
        cout << cur_vertex << " to " << v << endl;
        if (visited[v] == false) {
            if (max_on_path[v] < G[cur_vertex][i].second)
                max_on_path[v] = G[cur_vertex][i].second;

            if (max_on_path[v] < max_on_path[cur_vertex])
                max_on_path[v] = max_on_path[cur_vertex];

            return dfs(G, v, max_on_path, visited);
        }
    }

    return -1;
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
        G[u-1].push_back( make_pair(v-1, w) );
        G[v-1].push_back( make_pair(u-1, w) );
    }

    graph MST = Prims(G);

    vector<int> max_on_path( G.size() );
    max_on_path[0] = 0;
    vector<bool> visited( G.size() );
    visited[0] = 1;
    cout << dfs(MST, 0, max_on_path, visited) << endl;

    return 0;
}
