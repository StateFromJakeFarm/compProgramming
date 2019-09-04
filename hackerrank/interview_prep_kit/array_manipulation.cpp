#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Interval {
    long a, b, k;
    vector<Interval*> touches;
};

pair<long, long> no_intersection = make_pair(-1, -1);

pair<long, long> intersection(Interval *i1, Interval *i2) {
    if (i1->b >= i2->a && i1->a <= i2->b) {
        return make_pair(max(i1->a, i2->a), min(i1->b, i2->b));
    }

    return no_intersection;
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

    return 0;
}
