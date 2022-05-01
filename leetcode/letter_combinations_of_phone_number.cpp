#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<char, string> mapping({
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
});

void print(vector<string> &v) {
    for (auto &s : v) {
        cout << s << ", ";
    }
    cout << endl;
}

// Solution
class Solution {
public:
    vector<string> list;
    void helper(string &digits, string cur, unsigned idx) {
        if (idx >= digits.size()) {
            list.push_back(cur);
            return;
        }

        char digit = digits[idx];
        for (char &c : mapping[digit]) {
            helper(digits, cur + c, idx+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() > 0) {
            this->helper(digits, "", 0);
        }

        return list;
    }
};

int main() {
    Solution S;

    auto v = S.letterCombinations("23");
    print(v);

    return 0;
}
