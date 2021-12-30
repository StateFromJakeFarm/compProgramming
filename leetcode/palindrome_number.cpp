#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        }

        int l = 0, h = floor(log10(x));
        int l_v, h_v;
        while (l < h) {
            l_v = floor((x % (long)pow(10, l+1)) / pow(10, l));

            h_v = floor((x % (long)pow(10, h+1)) / pow(10, h));

            l++; h--;

            if (l_v != h_v) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution s;

    int x;
    cin >> x;

    cout << s.isPalindrome(x) << endl;

    return 0;
}
