#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Gather all bar heights as input
    vector<int> bars;
    int bar;
    while (cin >> bar) {
        bars.push_back(bar);
    }

    int n = bars.size();
    vector<int> R(n), L(n);

    // Prime initial positions so loop is more straightforward
    L[0] = bars[0];
    R[n-1] = bars[n-1];

    // Get maximum height on either side of each position
    for (int i = 1; i < n; i++) {
        L[i] = max(L[i-1], bars[i]);
        R[n-i-1] = max(R[n-i], bars[n-i-1]);
    }

    // Each position can hold the difference between the shortest bar between
    // the tallest of its left and right "girders" and its own height
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += max(0, min(L[i], R[i]) - bars[i]);
    }

    cout << water << endl;

    return 0;
}
