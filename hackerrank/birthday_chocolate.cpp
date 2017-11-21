#include <iostream>

using namespace std;

int main() {
    int num_ways = 0;

    int n, d, m;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++) {
        cin >> S[i];
    }
    cin >> d >> m;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<m; j++) {
            sum += S[i+j];
        }

        if(sum == d)
            ++num_ways;
    }

    cout << num_ways << endl;

    return 0;
}
