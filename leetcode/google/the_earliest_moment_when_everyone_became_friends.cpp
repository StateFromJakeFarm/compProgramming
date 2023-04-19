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
    int compress(vector<int> &ids, int idx) {
        while (ids[idx] != idx) {
            idx = ids[idx];
        }

        return idx;
    }

    int earliestAcq(vector<vector<int>>& logs, int n) {
        vector<int> ids(n);
        for (int i=0; i<n; i++) { ids[i] = i; }

        vector<int> sizes(n, 1);

        sort(logs.begin(), logs.end());
        int timestamp, n1, n2, n1_root, n2_root;
        for (auto &log : logs) {
            timestamp = log[0];
            n1 = log[1];
            n2 = log[2];

            // Compress paths so we know the roots
            n1_root = this->compress(ids, n1);
            n2_root = this->compress(ids, n2);
            ids[n1] = n1_root;
            ids[n2] = n2_root;

            // Combine CCs
            if (n1_root != n2_root) {
                ids[n2_root] = n1_root;
                sizes[n1_root] += sizes[n2_root];
            }

            if (sizes[n1_root] == n) {
                return timestamp;
            }
        }

        return -1;
    }
};


int main() {
    Solution S;

    vector<vector<int>> logs = {{0, 1, 0}};
    cout << S.earliestAcq(logs, 2) << endl;

    return 0;
}
