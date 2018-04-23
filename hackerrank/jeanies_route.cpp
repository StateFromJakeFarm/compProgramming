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
typedef vector<bool> vb;

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

void dfs(const long &cur, const adj_list &G, vl &dists, vl &parents) {
    for (long i=0; i<G[cur].size(); i++) {
        long child = G[cur][i].first;
        if (child == start || dists[child] != 0)
            continue;

        long child_dist = G[cur][i].second;
        dists[child] = dists[cur] + child_dist;

        parents[child] = cur;

        dfs(child, G, dists, parents);
    }
}

long dfs_min_cost(const long &cur, const adj_list &G, vb &seen, const table &diameter_vertices) {
    long cost = 0;
    for (long i=0; i<G[cur].size(); i++) {
        long child = G[cur][i].first;
        if (seen[child])
            continue;
        seen[child] = true;

        long dist = G[cur][i].second;
        if (diameter_vertices.find(cur) != diameter_vertices.end()) {
            if (diameter_vertices.find(child) != diameter_vertices.end()) {
                cost += (dist + dfs_min_cost(child, G, seen, diameter_vertices));
            } else {
                cost += 2*(dist + dfs_min_cost(child, G, seen, diameter_vertices));
            }
        } else {
            cost += (dist + dfs_min_cost(child, G, seen, diameter_vertices));
        }
    }

    return cost;
}

long get_furthest(vl &dists) {
    long furthest = 0;
    long max_dist = INT_MIN;

    for (long i=0; i<dists.size(); i++) {
        if (dists[i] > max_dist) {
            max_dist = dists[i];
            furthest = i;
        }
    }

    return furthest;
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
    vl parents(N);
    dfs_make_graph(start, G, G_new, letters, dists);

    // Get diametrically-opposed vertices
    for (long i=0; i<N; i++)
        dists[i] = 0;
    dfs(start, G_new, dists, parents);
    long s = get_furthest(dists);

    for (long i=0; i<N; i++)
        dists[i] = 0;
    start = s;
    parents[s] = s;
    dfs(s, G_new, dists, parents);
    long t = get_furthest(dists);

    // Get vertices on path between s and t
    table diameter_vertices;
    long i = t;
    while (i != s) {
        diameter_vertices[i] = true;
        i = parents[i];
    }
    diameter_vertices[i] = true;

    vb seen(N);
    seen[t] = true;
    cout << dfs_min_cost(t, G_new, seen, diameter_vertices) << endl;

    return 0;
}
