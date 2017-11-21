#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// Returns true if node 'a' is "good"
bool dfsVisit(vector< unordered_map<int, int> > & G, int a, int c, int p) {
    for(auto it=G[a].begin(); it!=G[a].end(); it++) {
        if(it->first == p)
            continue;

        if(it->second == c)
            return false;
        else if(!dfsVisit(G, it->first, it->second, a))
            return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    // Build the tree as graph
    vector< unordered_map<int, int> > G(n);
    int a, b, c;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> c;

        // Input is not zero-indexed
        a = a-1;
        b = b-1;
        c = c-1;

        G[a][b] = c;
        G[b][a] = c;
    }

    // Run dfsVisit() starting at every node to determine if it is "good"
    vector<int> goodNodes;
    for(int i=0; i<n; i++) {
        if(dfsVisit(G, i, INT_MAX, i))
            goodNodes.push_back(i+1);
    }

    // Print out all "good" nodes
    cout << goodNodes.size() << endl;
    for(int i=0; i<(int)goodNodes.size(); i++)
        cout << goodNodes[i] << endl;

    return 0;
}
