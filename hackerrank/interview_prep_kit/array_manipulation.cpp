#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Interval {
    long a, b, k;
    vector<Interval*> touches;
    bool visited = false;
};

pair<long, long> no_intersection = make_pair(-1, -1);

pair<long, long> intersection(Interval *i1, Interval *i2) {
    if (i1->b >= i2->a && i1->a <= i2->b) {
        return make_pair(max(i1->a, i2->a), min(i1->b, i2->b));
    }

    return no_intersection;
}

pair<long, long> intersection(const pair<long, long> &cur_interval, Interval *i2) {
    if (cur_interval.second >= i2->a && cur_interval.first <= i2->b) {
        return make_pair(max(cur_interval.first, i2->a),
            min(cur_interval.second, i2->b));
    }

    return no_intersection;
}

long long dfs_visit(Interval *interval, pair<long, long> cur_interval) {
    if (cur_interval == no_intersection) {
        return 0;
    }

    interval->visited = true;

    long long max_sum = interval->k;
    for (unsigned i=0; i<interval->touches.size(); i++) {
        if (!interval->touches[i]->visited) {
            max_sum = max(max_sum, interval->k + dfs_visit(interval->touches[i],
                intersection(cur_interval, interval->touches[i])));
        }
    }

    interval->visited = false;

    return max_sum;
}

int main() {
    long n, m;
    cin >> n >> m;
    vector<Interval> intervals(m);
    for (long i=0; i<m; i++) {
        cin >> intervals[i].a >> intervals[i].b >> intervals[i].k;
    }

    for (long i=0; i<m; i++) {
        for (long j=i+1; j<m; j++) {
            if (intersection(&intervals[i], &intervals[j]) != no_intersection) {
                intervals[i].touches.push_back(&intervals[j]);
                intervals[j].touches.push_back(&intervals[i]);
            }
        }
    }

    long long max_sum = 0;
    for (long i=0; i<m; i++) {
        max_sum = max(max_sum, dfs_visit(&intervals[i], make_pair(intervals[i].a, intervals[i].b)));
    }

    cout << max_sum << endl;

    return 0;
}
