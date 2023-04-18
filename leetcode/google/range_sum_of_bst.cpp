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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Find lower
        queue<TreeNode*> Q;
        Q.push(root);
        int sum = 0;
        TreeNode *cur;
        while (!Q.empty()) {
            cur = Q.front();
            Q.pop();
            if (cur == nullptr) {
                continue;
            }

            if (cur->val >= low && cur->val <= high) {
                sum += cur->val;
            }

            Q.push(cur->left);
            Q.push(cur->right);
        }

        return sum;
    }
};


int main() {
    Solution S;

    vector<int> in = {10,5,15,3,7,18};

    TreeNode *root = nullptr;
    for (auto v : in) {
        insert(root, v);
    }

    cout << S.rangeSumBST(root, 7, 15) << endl;

    return 0;
}
