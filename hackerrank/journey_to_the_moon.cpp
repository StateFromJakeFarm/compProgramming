#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex {
    vector<int> adj;
    int id;
    char c;
};

typedef vector<vertex> Graph;

int dfsVisit(Graph & G, int u, int id) {
    int numFound = 1;
    G[u].c = 'g';
    G[u].id = id;

    for(unsigned i=0; i<G[u].adj.size(); i++) {
        int v = G[u].adj[i];
        if(G[v].c == 'w') {
            numFound += dfsVisit(G, v, id);
        }
    }

    G[u].c = 'b';

    return numFound;
}

vector<int> dfs(Graph & G) {
    vector<int> idSizes;
    int id = 0;

    for(unsigned u=0; u<G.size(); u++)
        G[u].c = 'w';

    for(unsigned u=0; u<G.size(); u++) {
        if(G[u].c == 'w') {
            idSizes.push_back( dfsVisit(G, u, id));
            ++id;
        }
    }

    return idSizes;
}

int main() {
    long N, P;
    cin >> N >> P;

    Graph G;
    G.resize(N);

    int a1, a2;
    for(int i=0; i<P; i++) {
        cin >> a1 >> a2;

        G[a1].adj.push_back(a2);
        G[a2].adj.push_back(a1);
    }

    long numPairs = N*(N-1)/2;
    vector<int> idSizes = dfs(G);
    for(unsigned i=0; i<idSizes.size(); i++) {
        int webSize = idSizes[i];
        numPairs -= webSize*(webSize-1)/2;
    }
    cout << numPairs << endl;

    return 0;
}
