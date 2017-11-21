#include<iostream>
#include<vector>

using namespace std;

int explore(vector< vector<int> > &G, vector<bool> &visited, int cur, int costRoad, int numCities) {
    visited[cur] = true;

    int myCost = 0;
    for(int neighb=0; neighb<numCities; neighb++) {
        if(G[cur][neighb] && !visited[neighb]) {
            myCost += costRoad;
            myCost += explore(G, visited, neighb, costRoad, numCities);
        }
    }

    return myCost;
}

int main() {
    int Q;
    cin >> Q;

    for(int q=0; q<Q; q++) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        if(l < r) {
            cout << l*n << endl;
            return 0;
        }

        vector< vector<int> > G;
        G.resize(n);
        for(int i=0; i<n; i++)
            G[i].resize(n);

        vector<bool> visited(n);
        for(int p=0; p<m; p++) {
            int from, to;
            cin >> from >> to;

            G[from-1][to-1] = 1;
        }

        int totalCost = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                totalCost += l;
                totalCost += explore(G, visited, i, r, n);
            }
        }
        cout << totalCost << endl;
    }

    return 0;
}
