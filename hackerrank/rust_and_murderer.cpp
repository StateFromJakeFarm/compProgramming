#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef vector<long> vl;
typedef vector<vl> vvl;
typedef vector< unordered_map<long, bool> > inverse;

void bfs(vvl &G, const long &S, vl &dist) {
    vector<short> color( G.size() );
    queue<long> Q;

    color[S] = 1;
    dist[S] = 0;
    Q.push(S);

    long u;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (long i=0; i<(long)G[u].size(); i++) {
            long v = G[u][i];
            if (color[v] == 0) {
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

        inverse G_inv(N);
        for (int m=0; m<M; m++) {
            cin >> x >> y;
            x--; y--;

            G_inv[x][y] = true;
            G_inv[y][x] = true;
        }

        vvl G(N);
        for (long n=0; n<N; n++)
            for (long q=0; q<N; q++)
                if (q != n && G_inv[n].find(q) == G_inv[n].end())
                    G[n].push_back(q);

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
