#include <iostream>
#include <cmath>

using namespace std;

void absPerm(int n, int k) {
    for(int i=1; i<=n; i++) {
        if(((i-1)/k)%2 == 0) {
            cout << i + k;
        } else {
            cout << i - k;
        }

        cout << " ";
    }
}

int main() {
    int t;
    cin >> t;

    int n, k;
    for(int i=0; i<t; i++) {
        cin >> n >> k;

        if(k == 0) {
            for(int i=1; i<=n; i++) {
                cout << i << " ";
            }
        } else if(k <= n/2 && n%k == 0 && (n/k)%2 == 0) {
            absPerm(n, k);
        } else {
            cout << "-1";
        }

        cout << endl;
    }

    return 0;
}
