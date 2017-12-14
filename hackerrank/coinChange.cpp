#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long n, m;
    cin >> n >> m;

    if(n == 0 || m == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<long> C(m);
    for(long i=0; i<m; i++)
        cin >> C[i];

    vector<long> T(n+1);
    T[0] = 1;
    for(int i=0; i<m; i++) {
        for(int j=C[i]; j<=n; j++)
            T[j] += T[ j-C[i] ];
    }

    cout << T[n] << endl;

    return 0;
}
