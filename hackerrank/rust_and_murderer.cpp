#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef vector<long> vl;
typedef vector< unordered_map<long, bool> > Graph;

void bfs(Graph &G, const long &S, vl &dist) {
    vector<short> color( G.size() );
    queue<long> Q;

    color[S] = 1;
    dist[S] = 0;
    Q.push(S);

    long u;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (long v=0; v<(long)G.size(); v++) {
            // This is a village road to an unvisited node
            if (v != u && G[u].find(v) == G[u].end() && color[v] == 0) {
                color[v] = 1;
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
        color[u] = 2;
    }
}

int main() {
    long T, N, M, x, y, S;

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> N >> M;

        Graph G(N);
        for (int m=0; m<M; m++) {
            cin >> x >> y;
            x--; y--;

            G[x][y] = true;
            G[y][x] = true;
        }

        cin >> S;
        S--;

        vl dist(N);
        bfs(G, S, dist);

        for (long n=0; n<N; n++)
            if (n != S)
                cout << dist[n] << ' ';
        cout << endl;
    }

    return 0;
}
