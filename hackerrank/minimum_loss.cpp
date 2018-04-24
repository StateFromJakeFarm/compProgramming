#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>
#include <functional>

using namespace std;

int main() {
    long n;
    cin >> n;

    vector< tuple<long,long> > prices;
    long p;
    for (long i=0; i<n; i++) {
        cin >> p;
        prices.push_back( make_tuple(p, i) );
    }

    // Sort in descending order
    sort(prices.begin(), prices.end());

    long min_diff = INT_MAX;
    for (long i=n-1; i>0; i--) {
        if (get<0>(prices[i]) > get<0>(prices[i-1]) && get<1>(prices[i]) < get<1>(prices[i-1]))
            min_diff = min(min_diff, get<0>(prices[i]) - get<0>(prices[i-1]));
    }

    cout << min_diff << endl;

    return 0;
}
