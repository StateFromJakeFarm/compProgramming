#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    cin >> N;

    long kids[N];
    long l[N];
    long r[N];

    fill_n(l, N, 1);
    fill_n(r, N, 1);

    for(int i=0; i<N; i++)
        cin >> kids[i];

    for(int i=0; i<N-1; i++) {
        if(kids[i] < kids[i+1])
            r[i+1] = r[i] + 1;
    }

    for(int i=N-1; i>0; i--) {
        if(kids[i] < kids[i-1])
            l[i-1] = l[i] + 1;
    }

    long maxsSum = 0;
    for(int i=0; i<N; i++)
        maxsSum += max(r[i], l[i]);

    cout << maxsSum << endl;

    return 0;
}
