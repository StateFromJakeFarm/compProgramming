#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        string sorted;
        for (auto &s : strs) {
            sorted = s;
            sort(sorted.begin(), sorted.end());
            table[sorted].push_back(s);
        }

        vector<vector<string>> groups;
        for (auto it : table) {
            groups.push_back(it.second);
        }

        return groups;
    }
};

void print(vector<vector<string>> groups) {
    for (vector<string> &group : groups) {
        for (string &s : group) {
            cout << s << ' ';
        }
        cout << endl;
    }
}

int main() {
    Solution S;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto groups = S.groupAnagrams(strs);
    print(groups);

    return 0;
}
