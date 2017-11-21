#include <iostream>
#include <vector>

using namespace std;

class Vertex {
    public:
    char c = 'w';
    vector<int> adj;
};

typedef vector<Vertex> Graph;

int dfsVisit(Graph & G, int u, int & needed) {
    int mySubtree = 1;
    G[u].c = 'g';

    for(unsigned i=0; i<G[u].adj.size(); i++) {
        int v = G[u].adj[i];
        if(G[v].c == 'w') {
            int childSubtree = dfsVisit(G, v, needed);
            if(childSubtree % 2 == 1) {
                mySubtree += childSubtree;
                ++needed;
            }
        }
    }

    G[u].c = 'b';

    return mySubtree;
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);

    int u, v;
    for(int e=0; e<M; e++) {
        cin >> u >> v;
        --u; --v;

        G[u].adj.push_back(v);
        G[v].adj.push_back(u);
    }

    int needed = 0;
    dfsVisit(G, 0, needed);
    cout << M - needed << endl;

    return 0;
}
