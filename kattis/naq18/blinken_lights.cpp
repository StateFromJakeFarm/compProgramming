#include <iostream>
#include <cmath>

using namespace std;

int lcm(int p, int q) {
    int sum_p = p;
    int sum_q = q;
    while (sum_p != sum_q) {
        if (sum_p < sum_q) {
            sum_p += p;
        } else {
            sum_q += q;
        }
    }

    return sum_p;
}

int main() {
    int p, q, s;
    cin >> p >> q >> s;

    int big, small;
    if (p > q) {
        big = p;
        small = q;
    } else {
        big = q;
        small = p;
    }

    if (lcm(p, q) <= s) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
