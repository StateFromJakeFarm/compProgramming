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
    int removeDuplicates(vector<int>& nums) {
        int max = -101;
        int p = 0;
        for (unsigned i=0; i<nums.size(); i++) {
            if (nums[i] > max) {
                nums[p] = nums[i];
                p++;
                max = nums[i];
            }
        }

        nums.resize(p);

        return p;
    }
};


int main() {
    Solution S;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << S.removeDuplicates(nums) << endl;
    print_vec(nums);

    return 0;
}
