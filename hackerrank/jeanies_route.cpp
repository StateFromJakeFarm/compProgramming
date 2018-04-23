#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

typedef vector< vector< pair<long,long> > > adj_list;
typedef unordered_map<long, bool> table;
typedef vector<bool> vb;

bool dfs(const long &cur, const adj_list &G, adj_list &G_new, const table &letters, vb &seen) {
    bool saw_letter = false;
    for (long i=0; i<G[cur].size(); i++) {
        long child = G[cur][i].first;
        if (seen[child])
            continue;
        seen[child] = true;

        long dist = G[cur][i].second;

        bool child_has_letter = dfs(child, G, G_new, letters, seen);
        if (!saw_letter)
            saw_letter = child_has_letter;

        if (child_has_letter) {
            G_new[cur].push_back(make_pair(child, dist));
            G_new[child].push_back(make_pair(cur, dist));
        }
    }

    if (!saw_letter)
        saw_letter = (letters.find(cur) != letters.end());

    return saw_letter;
}

int main() {
    long N, K;
    cin >> N >> K;

    long start;
    table letters;
    for (long k=0; k<K; k++) {
        long city;
        cin >> city;
        city--;

        if (k == 0)
            start = city;

        letters[city] = true;
    }

    adj_list G(N);
    long u, v, d;
    for (long n=0; n<N-1; n++) {
        cin >> u >> v >> d;
        u--; v--;
        G[u].push_back(make_pair(v, d));
        G[v].push_back(make_pair(u, d));
    }

    // G_new is tree without throwaway paths (no letter cities in them)
    adj_list G_new(N);
    vb seen(N);
    seen[start] = true;
    dfs(start, G, G_new, letters, seen);

    return 0;
}
