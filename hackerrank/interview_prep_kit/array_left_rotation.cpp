#include <iostream>

using namespace std;

int main() {
    unsigned n, d;
    cin >> n >> d;

    unsigned arr[n];
    for (unsigned i=0; i<n; i++) {
        cin >> arr[i];
    }

    unsigned q = d % n;
    for (unsigned i=0; i<n; i++) {
        if (q >= n) {
            q = 0;
        }

        cout << arr[q] << ' ';

        q++;
    }
    cout << endl;

    return 0;
}
