#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = 0;
        char cur = 1;
        while (cur) {
            cur = strs[0][l];
            for (string &s : strs) {
                if (s[l] != cur) {
                    cur = 0;
                    break;
                }
            }
            l++;
        }

        return strs[0].substr(0, l-1);
    }
};


int main() {
    Solution S;

    vector<string> strs = {"flower","flow","flight"};

    cout << S.longestCommonPrefix(strs) << endl;

    return 0;
}
