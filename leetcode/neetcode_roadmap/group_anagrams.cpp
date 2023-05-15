#include <bits/stdc++.h>

using namespace std;


void print_vec(vector<vector<string>> vec) {
    for (auto &v : vec) {
        for (auto &s : v) {
            cout << s << ' ';
        }
        cout << endl;
    }
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void insert(TreeNode* &root, int val) {
    TreeNode *n = new TreeNode(val);

    if (root == nullptr) {
        root = n;
        return;
    }

    TreeNode *cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left == nullptr) {
                cur->left = n;
                cout << val << " to the left of " << cur->val << endl;
                break;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == nullptr) {
                cur->right = n;
                cout << val << " to the right of " << cur->val << endl;
                break;
            } else {
                cur = cur->right;
            }
        }
    }
}


class Solution {
public:
    vector<int> primes = {
        2,
        3,
        5,
        7,
        11,
        13,
        17,
        19,
        23,
        29,
        31,
        37,
        41,
        43,
        47,
        53,
        59,
        61,
        67,
        71,
        73,
        79,
        83,
        89,
        97,
        101,
        103
    };

    unsigned long long hash(string &s) {
        unsigned long long key = 1;
        for (char &c : s) {
            key *= primes[c - 'a' + 1];
        }

        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unsigned long long, vector<string>> map;
        for (auto str : strs) {
            map[hash(str)].push_back(str);
        }

        vector<vector<string>> groups;
        int g = 0;
        for (auto v : map) {
            groups.resize(g + 1);
            for (string &s : v.second) {
                groups[g].emplace_back(s);
            }
            g++;
        }

        return groups;
    }
};


int main() {
    Solution S;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    print_vec(S.groupAnagrams(strs));

    return 0;
}
