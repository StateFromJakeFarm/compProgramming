#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

typedef vector< vector< pair<unsigned long long, unsigned long long> > > graph;

vector<unsigned long long> dijkstras(graph G, unsigned long long s) {
    vector<unsigned long long> distArray(G.size());
    vector<unsigned long long> Q;

    for(unsigned long long i=0; i<G.size(); i++) {
        if(i != s)
            distArray[i] = UINT_MAX*2;
        else
            distArray[i] = 0;

        Q.push_back(i);
    }

    while(Q.size()) {
        unsigned long long uDist = UINT_MAX*2;
        unsigned long long u, uIndex = 0;
        for(unsigned long long i=0; i<Q.size(); i++) {
            if(distArray[ Q[i] ] < uDist) {
                u = Q[i];
                uIndex = i;
                uDist = distArray[u];
            }
        }
        Q.erase(Q.begin() + uIndex);

        unsigned long long v;
        unsigned long long uTov;
        for(unsigned long long i=0; i<G[u].size(); i++) {
            v = G[u][i].first;
            uTov = G[u][i].second;

            if(distArray[v] > distArray[u] + uTov)
                distArray[v] = distArray[u] + uTov;
        }
    }

    return distArray;
}

int main() {
    unsigned long long n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;

    graph G;
    G.resize(n);

    unsigned long long i, j, c;
    for(unsigned long long q=0; q<m; q++) {
        cin >> i >> j >> c;
        G[i].push_back( make_pair(j, c) );
        G[j].push_back( make_pair(i, c) );
    }

    vector<unsigned long long> distS = dijkstras(G, s);
    vector<unsigned long long> distT = dijkstras(G, t);

    unsigned long long bestPrice = distS[t];
    unsigned long long u, v;
    for(unsigned long long i=0; i<f; i++) {
        cin >> u >> v;
        bestPrice = min(bestPrice, distS[u] + distT[v]);
    }

    cout << bestPrice << endl;

    return 0;
}
