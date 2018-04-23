#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

typedef vector< vector< pair<long,long> > > adj_list;
typedef unordered_map<long, bool> table;
typedef vector<long> vl;

long start;

bool dfs_make_graph(const long &cur, const adj_list &G, adj_list &G_new, const table &letters, vl &dists) {
    bool saw_letter = false;
    for (long i=0; i<G[cur].size(); i++) {
        long child = G[cur][i].first;
        if (child == start || dists[child] != 0)
            continue;

        long child_dist = G[cur][i].second;
        dists[child] = dists[cur] + child_dist;

        bool child_has_letter = dfs_make_graph(child, G, G_new, letters, dists);
        if (!saw_letter)
            saw_letter = child_has_letter;

        if (child_has_letter) {
            G_new[cur].push_back(make_pair(child, G[cur][i].second));
            G_new[child].push_back(make_pair(cur, G[cur][i].second));
        }
    }

    if (!saw_letter)
        saw_letter = (letters.find(cur) != letters.end());

    return saw_letter;
}

void dfs(const long &cur, const adj_list &G, vl &dists) {
    for (long i=0; i<G[cur].size(); i++) {
        long child = G[cur][i].first;
        if (child == start || dists[child] != 0)
            continue;

        long child_dist = G[cur][i].second;
        dists[child] = dists[cur] + child_dist;

        dfs(child, G, dists);
    }
}

int main() {
    long N, K;
    cin >> N >> K;

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
    vl dists(N);
    dfs_make_graph(start, G, G_new, letters, dists);

    for (long i=0; i<N; i++)
        dists[i] = 0;
    dfs(start, G_new, dists);

    long furthest_from_start;
    long max_dist = INT_MIN;
    for (long i=0; i<N; i++) {
        if (dists[i] > max_dist) {
            max_dist = dists[i];
            furthest_from_start = i;
        }
    }

    return 0;
}
