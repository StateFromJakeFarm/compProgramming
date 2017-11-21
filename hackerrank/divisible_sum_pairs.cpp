#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int A[n];
    for(int i=0; i<n; i++)
        cin >> A[i];

    int pairs = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if( (A[i] + A[j]) % k == 0)
                ++pairs;
        }
    }

    cout << pairs << endl;

    return 0;
}
