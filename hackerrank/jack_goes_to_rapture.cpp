#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

void dfs(const vector< vector< pair<int, long> > > &G, vector<long> &max_on_path, const int u) {
    int v;
    long c, max_to_v_from_u;
    for (int j=0; j<G[u].size(); j++) {
        v = G[u][j].first;
        c = G[u][j].second;

        max_to_v_from_u = max(max_on_path[u], c);

        if (max_on_path[v] > max_to_v_from_u) {
            max_on_path[v] = max_to_v_from_u;
            dfs(G, max_on_path, v);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector< vector< pair<int, long> > > G(N);
    int u, v, c;
    for (int i=0; i<E; i++) {
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back( make_pair(v, c) );
        G[v].push_back( make_pair(u, c) );
    }

    vector<long> max_on_path(G.size(), LONG_MAX);
    max_on_path[0] = 0;
    dfs(G, max_on_path, 0);

    if (max_on_path[N-1] == LONG_MAX) {
        cout << "NO PATH EXISTS" << endl;
    } else {
        cout << max_on_path[N-1] << endl;
    }

    return 0;
}
