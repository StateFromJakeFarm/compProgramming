#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

typedef vector<long> vi;
typedef vector<vi> adj_list;
typedef unordered_map<long, bool> hash_table;

void add_edge(adj_list & adj, hash_table & not_alone, long u, long v) {
    adj[u].push_back(v);
    adj[v].push_back(u);

    not_alone[v] = true;
    not_alone[u] = true;
}

void dfs(const adj_list & adj, vi & visited, long u, long & sum) {
    sum++;
    visited[u] = 1;

    for (long i=0; i<(long)adj[u].size(); i++) {
        long neighbor = adj[u][i];
        if (visited[neighbor] == 0)
            dfs(adj, visited, neighbor, sum);
    }
}

int main() {
    long N, P;
    cin >> N >> P;

    long num_alone = N;
    hash_table not_alone;

    vi visited(N);
    adj_list adj(N);
    long u, v;
    for (long p=0; p<P; p++) {
        cin >> u >> v;

        if (not_alone.find(u) == not_alone.end())
            num_alone--;
        if (not_alone.find(v) == not_alone.end())
            num_alone--;

        add_edge(adj, not_alone, u, v);
    }
    cout << num_alone << endl;

    vi cc_sizes;
    for (long n=0; n<N; n++) {
        if (visited[n] == 0 && not_alone.find(n) != not_alone.end()) {
            long size = 0;
            dfs(adj, visited, n, size);
            cc_sizes.push_back(size);
        }
    }

    long total = 0;
    for (long i=0; i<(long)cc_sizes.size(); i++) {
        total += cc_sizes[i] * num_alone;
        for (long j=i+1; j<(long)cc_sizes.size(); j++) {
            total += cc_sizes[i] * cc_sizes[j];
        }
    }
    total += num_alone * (num_alone-1) / 2;

    cout << total << endl;

    return 0;
}
