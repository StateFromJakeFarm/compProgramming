#include <iostream>
#include <vector>

using namespace std;

class Vertex {
    public:
    vector<int> adj;
    int mine;

    Vertex() {
        mine = -1;
    }
};

void dfsVisit(vector<Vertex> & G, int u) {
    for(unsigned i=0; i<G[u].adj.size(); i++) {
        int v = G[u].adj[i];
        if(G[v].mine == -1 || (G[v].mine != -1 && G[v].mine != u) ) {
            G[u].mine = v;
            cout << v << " " << u << endl;
            dfsVisit(G, v);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<Vertex> G(n+1);
    int u, v;
    for(int i=0; i<n; i++) {
        cin >> u >> v;

        G[u].adj.push_back(v);
        G[v].adj.push_back(u);
    }

    // Do a sweep for weird memes
    for(int i=0; i<n; i++) {
        u = i+1;
        if(G[u].adj.size() == 1) {
            v = G[u].adj[0];
            G[v].mine = u;
            cout << v << " " << u << endl;
        } else if(G[u].adj.size() == 2 && G[u].adj[0] == G[u].adj[1]) {
            v = G[u].adj[0];
            G[u].mine = v;
            G[v].mine = u;

            cout << u << " " << v << endl;
            cout << v << " " << u << endl;
        }
    }

    for(int i=0; i<n; i++) {
        u = i+1;
        if(G[u].mine == -1)
            dfsVisit(G, u);
    }

    return 0;
}
