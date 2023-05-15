#include <bits/stdc++.h>

using namespace std;


void print_vec(vector<int>& vec) {
    for (auto &v : vec) {
        cout << v << ' ';
    }
    cout << endl;
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
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        for (char c : t) {
            counts[c - 'a']--;
        }

        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution S;

    string s = "car";
    string t = "rat";

    cout << S.isAnagram(s, t) << endl;

    return 0;
}
