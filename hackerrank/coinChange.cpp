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

    vector<long> C(n+1);
    long coin;
    for(long i=0; i<m; i++) {
        cin >> coin;

        if(coin <= n)
            C[coin] = 1;
    }

    for(long i=1; i<=n; i++) {
        for(long j=i-1; j>i/2; j--) {
            if(C[j] && C[i-j])
                C[i] += C[j] * C[i-j];
        }
    for(int q=1; q<=n; q++)
        cout << C[q] << " ";
    cout << endl;
    }

    cout << C[n] << endl;

    return 0;
}
