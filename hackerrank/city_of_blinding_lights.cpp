#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<long> vl;
typedef vector<vl> vvl;

int main() {
    long N, M, Q;
    cin >> N >> M;

    vvl dist(N);
    for (long i=0; i<N; i++)
        dist[i].resize(N);
    for (long i=0; i<N; i++) {
        fill( dist[i].begin(), dist[i].end(), INT_MAX );
        dist[i][i] = 0;
    }

    long x, y, r;
    for (long m=0; m<M; m++) {
        cin >> x >> y >> r;
        x--; y--;

        dist[x][y] = r;
    }

    // Run Floyd-Warshall
    for (long k=0; k<N; k++) {
        for (long i=0; i<N; i++) {
            for (long j=0; j<N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cin >> Q;
    long a, b;
    for (long q=0; q<Q; q++) {
        cin >> a >> b;
        a--; b--;

        if (dist[a][b] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dist[a][b] << endl;
    }

    return 0;
}
