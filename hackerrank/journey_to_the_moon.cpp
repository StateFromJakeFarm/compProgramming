#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> adj_list;

void add_edge(adj_list & adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(const adj_list & adj, vi & visited, int u, int & sum) {
    sum++;
    visited[u] = 1;

    for (int i=0; i<(int)adj[u].size(); i++) {
        int neighbor = adj[u][i];
        if (visited[neighbor] == 0)
            dfs(adj, visited, neighbor, sum);
    }
}

int main() {
    int N, P;
    cin >> N >> P;

    vi visited(N);
    adj_list adj(N);
    int u, v;
    for (int p=0; p<P; p++) {
        cin >> u >> v;
        add_edge(adj, u, v);
    }

    vi cc_sizes;
    for (int n=0; n<N; n++) {
        if (visited[n] == 0) {
            int sum = 0;
            dfs(adj, visited, n, sum);
            cc_sizes.push_back(sum);
        }
    }

    int total = 0;
    for (int i=0; i<(int)cc_sizes.size(); i++) {
        for (int j=i+1; j<(int)cc_sizes.size(); j++) {
            total += cc_sizes[i] * cc_sizes[j];
        }
    }

    cout << total << endl;

    return 0;
}
