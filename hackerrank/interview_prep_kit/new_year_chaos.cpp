#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;

        int arr[n];
        for (int i=0; i<n; i++) {
            cin >> arr[i];
            arr[i]--;
        }

        int bribes = 0;
        for (int i=0; i<n; i++) {
            if (arr[i] - i > 2) {
                bribes = -1;
                break;
            }

            for (int j=max(0, arr[i]-1); j<i; j++) {
                if (arr[j] > arr[i]) {
                    bribes++;
                }
            }
        }

        if (bribes != -1) {
            cout << bribes << endl;
        } else {
            cout << "Too chaotic" << endl;
        }
    }

    return 0;
}
