#include<iostream>

using namespace std;

int main() {
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;

    int d;
    int loc;
    int apples = 0;
    for(int i=0; i<m; i++) {
        cin >> d;
        loc = a + d;
        if(loc >= s && loc <= t)
            ++apples;
    }

    int oranges = 0;
    for(int i=0; i<n; i++) {
        cin >> d;
        loc = b + d;
        if(loc >= s && loc <= t)
            ++oranges;
    }

    cout << apples << endl << oranges << endl;

    return 0;
}
