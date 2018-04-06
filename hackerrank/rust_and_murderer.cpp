#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef vector<long> vl;
typedef vector<vl> vvl;

long bfs(vvl &G, const long &S, vl &dist) {
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

        cin >> S;
        S--;

        unordered_map<long, bool> neighbors;
        vvl G(N);
        for (int m=0; m<M; m++) {
            cin >> x >> y;
            x--; y--;

            G[x].push_back(y);
            G[y].push_back(x);

            if (x == S)
                neighbors[y] = true;
            if (y == S)
                neighbors[x] = true;
        }

        vl dist(N);
        bfs(G, S, dist);

        long total = N*(N-1)/4;
        long quarter_total = ceil(total/2);
        for (long n=0; n<N; n++)
            if (n != S) {
                if (neighbors.find(n) != neighbors.end())
                    cout << quarter_total - dist[n] << ' ';
                else
                    cout << 1 << ' ';
            }
        cout << endl;
    }

    return 0;
}
