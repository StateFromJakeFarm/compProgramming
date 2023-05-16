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
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 2) {
            vector<int> answer = {nums[1], nums[0]};

            return answer;
        }

        int zero_idx = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                if (zero_idx > -1) {
                    // Multiple zeros; all answers will be zero
                    vector<int> answer(nums.size(), 0);

                    return answer;
                }

                zero_idx = i;
            }
        }
        if (zero_idx > -1) {
            // Only 1 zero; zero index is product of all other nums and all other indeces are 0
            vector<int> answer(nums.size(), 0);
            int product = 1;
            for (int i=0; i<nums.size(); i++) {
                if (i == zero_idx) { continue; }
                product *= nums[i];
            }

            answer[zero_idx] = product;

            return answer;
        }

        int ltor[nums.size()];
        ltor[0] = nums[0];

        int rtol[nums.size()];
        rtol[nums.size() - 1] = nums[nums.size() - 1];

        for (int i=1; i<nums.size(); i++) {
            ltor[i] = ltor[i-1] * nums[i];
        }

        for (int i=nums.size()-2; i>=0; i--) {
            rtol[i] = rtol[i+1] * nums[i];
        }

        vector<int> answer(nums.size());
        answer[0] = rtol[1];
        answer[nums.size() - 1] = ltor[nums.size() - 2];
        for (int i=1; i<nums.size()-1; i++) {
            answer[i] = ltor[i-1] * rtol[i+1];
        }

        return answer;
    }
};


int main() {
    vector<int> nums = {1,2,3,4};
    Solution S;
    auto answer = S.productExceptSelf(nums);
    print_vec(answer);

    return 0;
}
