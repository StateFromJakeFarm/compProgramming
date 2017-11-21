#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t=0; t<T; t++) {
        int n;
        cin >> n;

        int vals[n];
        int min = INT_MAX;
        for(int i=0; i<n; i++) {
            int cur;
            cin >> cur;

            if(cur < min)
                min = cur;

            vals[i] = cur;
        }

        int opers[6];
        for(int j=0; j<=5; j++) {
            opers[j] = 0;
            for(int i=0; i<n; i++) {
                int val = abs(vals[i] - min + j);
                if(val >= 5) {
                    opers[j] += val / 5;
                    val %= 5;
                }

                if(val >= 2) {
                    opers[j] += val / 2;
                    val %= 2;
                }

                opers[j] += val;
            }
        }

        cout << *min_element(opers, opers+6) << endl;
    }

    return 0;
}
