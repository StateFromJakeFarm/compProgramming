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
                break;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == nullptr) {
                cur->right = n;
                break;
            } else {
                cur = cur->right;
            }
        }
    }
}


class Solution {
public:
    void push_safe(vector<vector<int>> &v, int idx, int &val) {
        if (v.size() <= idx) {
            v.resize(idx + 1);
        }
        v[idx].push_back(val);
    }

    int visit(vector<vector<int>> &out, TreeNode *cur) {
        if (cur->left == nullptr && cur->right == nullptr) {
            // Finally reached first set of leaves; start the ascension count
            this->push_safe(out, 0, cur->val);

            return 1;
        }

        int l_round = INT_MIN;
        int r_round = INT_MIN;
        if (cur->left != nullptr) {
            l_round = visit(out, cur->left);
        }
        if (cur->right != nullptr) {
            r_round = visit(out, cur->right);
        }

        int my_round = max(l_round, r_round);
        this->push_safe(out, my_round, cur->val);

        return my_round + 1;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> out;

        visit(out, root);

        return out;
    }
};


int main() {
    Solution S;

    TreeNode *root = nullptr;
    vector<int> in = {4,3,1,2,5};
    for (int v : in) {
        insert(root, v);
    }

    vector<vector<int>> out = S.findLeaves(root);
    for (auto &o : out) {
        print_vec(o);
    }

    return 0;
}
