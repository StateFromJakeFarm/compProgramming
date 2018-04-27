#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int longest_cycle = 0;

void dfs(const vvi &G, vi &disc_time, vi &parent, int time, int cur) {
    disc_time[cur] = time;
    for (int n : G[cur]) {
        if (parent[cur] != n) {
            if (disc_time[n] != -1) {
                // This node has been visited before, update longest cycle
                longest_cycle = max(longest_cycle, time - disc_time[n] + 1);
            } else {
                // Visit this node
                parent[n] = cur;
                dfs(G, disc_time, parent, time+1, n);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vvi G(N);
    vi disc_time(N, -1);
    vi parent(N, -1);
    int u, v;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(G, disc_time, parent, 0, 0);

    cout << longest_cycle << endl;

    return 0;
}
