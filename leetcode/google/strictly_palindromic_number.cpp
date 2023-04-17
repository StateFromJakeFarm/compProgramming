#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        // Because a number's representation in base n-2 will always be 12 (duh)
        return false;
    }
};


int main() {
    Solution S;
    for (int i=4; i<=10000; i++) {
        if (S.isStrictlyPalindromic(i)) {
            cout << i << endl;
        }
    }

    return 0;
}
