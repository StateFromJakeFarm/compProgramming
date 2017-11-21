#include <iostream>

using namespace std;

int main() {
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if(x1 == x2) {
        cout << "YES" << endl;
    } else if((x1 > x2 && v1 > v2) || (x2 > x1 && v2 > v1)) {
        cout << "NO" << endl;
    } else {
        int i = 0;
        while(true) {
            x1 += v1;
            x2 += v2;

            if(x1 == x2) {
                cout << "YES" << endl;
                break;
            } else if(i > 10000) {
                cout << "NO" << endl;
                break;
            }

            ++i;
        }
    }

    return 0;
}
