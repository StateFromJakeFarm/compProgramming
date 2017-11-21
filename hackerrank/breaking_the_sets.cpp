#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = INT_MAX;
    int h = 0;

    int nl = 0;
    int nh = 0;

    int s;
    for(int i=0; i<n; i++) {
        cin >> s;

        if(s < l) {
            l = s;

            if(i > 0)
                ++nl;
        }
        if(s > h) {
            h = s;

            if(i > 0)
                ++nh;
        }
    }

    cout << nh << " " << nl << endl;

    return 0;
}
