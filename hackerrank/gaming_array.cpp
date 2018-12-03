#include <iostream>
#include <climits>

using namespace std;

int main() {
    long g, n, cur_max, cur, maxes;
    cin >> g;
    for (long t=0; t<g; t++) {
        cin >> n;

        maxes = 0;
        cur_max = INT_MIN;
        for (long i=0; i<n; i++) {
            cin >> cur;
            if (cur > cur_max) {
                cur_max = cur;
                maxes++;
            }
        }

        if (maxes % 2) {
            cout << "BOB" << endl;
        } else {
            cout << "ANDY" << endl;
        }
    }

    return 0;
}
