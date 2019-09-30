#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    bool is_num(char c) {
        return (c >= '0' && c <= '9');
    }

    bool is_valid(char c) {
        return c == '+' || c == '-' ||
               is_num(c);
    }

    int myAtoi(string str) {
        // Eat whitespace
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }

        if (!is_valid(str[i])) {
            // Weird corner case
            return 0;
        }

        // Find actual numerical part
        int start = -1, end = -1;
        for (; i<(int)str.length() && is_valid(str[i]); i++) {
            if (start == -1) {
                start = i;
            }
            end = i;
        }

        if (is_valid(str[start]) && !is_num(str[start+1])) {
            return 0;
        }

        // Determine if negative
        bool is_neg = false;
        if (str[start] == '-') {
            is_neg = true;
            start++;
        }

        if (str[start] == '+') {
            start++;
        }

        if (start == end && !is_num(str[start])) {
            return 0;
        }

        // Do conversion
        int len = end - start;
        long res = 0;
        for (int j=0; start+j <= end; j++) {
            res += (str[start+j]-'0') * pow(10, len-j);
        }

        if (is_neg) {
            // Convert to negative number
            res *= -1;
        }

        if (res > INT_MAX) {
            return INT_MAX;
        }
        if (res < INT_MIN) {
            return INT_MIN;
        }

        return (int)res;
    }
};

int main() {
    Solution S;
    string str = "  +422";

    cout << S.myAtoi(str) << endl;

    return 0;
}
