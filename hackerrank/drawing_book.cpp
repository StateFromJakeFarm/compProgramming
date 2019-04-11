#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    if (n % 2 == 0) {
        n++;
    }

    cout << min(p/2, (n-p)/2) << endl;

    return 0;
}
