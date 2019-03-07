#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector< unordered_set<long> > &G, const long &S, vector<long> &dist) {
    queue<long> Q;
    Q.push(S);

    long v;
    while (!Q.empty()) {
        v = Q.pop();
    }
}

int main() {
    long T, N, M, S, x, y;

    cin >> T;
    for (long t=0; t<T; t++) {
        cin >> N >> M;
        vector< unordered_set<long> > G;

        for (long m=0; m<M; m++) {
            cin >> x >> y;
            x--; y--;
            G[x].insert(y);
            G[y].insert(x);
        }
        cin >> S;
        S--;

        vector<long> dist(N, -1);
        bfs(G, S, dist);
        for (long n=0; n<N; n++) {
            if (n != S) {
                cout << dist[n] << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
