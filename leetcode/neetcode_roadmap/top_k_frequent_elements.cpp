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
    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int partition(vector<int> &arr, int lo, int hi) {
        int pivot = arr[hi];
        int i = lo;
        for (int j=lo; j<hi; j++) {
            if (arr[j] >= pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, hi);

        return i;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_count;
        for (int &num : nums) {
            num_to_count[num]++;
        }

        if (num_to_count.size() == k) {
            vector<int> top_k;
            for (auto it : num_to_count) {
                top_k.push_back(it.first);
            }

            return top_k;
        }

        unordered_map<int, vector<int>> count_to_nums;
        vector<int> counts;
        for (auto it : num_to_count) {
            count_to_nums[it.second].push_back(it.first);
            counts.push_back(it.second);
        }

        int pivot_idx = -1;
        int lo = 0;
        int hi = counts.size() - 1;
        while (pivot_idx != k) {
            pivot_idx = partition(counts, lo, hi);

            if (pivot_idx < k) {
                lo = pivot_idx + 1;
            } else {
                hi = pivot_idx - 1;
            }
        }

        vector<int> top_k;
        unordered_set<int> seen;
        for (int i=0; i<k; i++) {
            if (seen.find(counts[i]) != seen.end()) {
                continue;
            }

            for (int num : count_to_nums[counts[i]]) {
                top_k.push_back(num);
            }
            seen.insert(counts[i]);
        }

        return top_k;
    }
};


int main() {
    Solution S;
    vector<int> nums = {6,0,1,4,9,7,-3,1,-4,-8,4,-7,-3,3,2,-3,9,5,-4,0};

    vector<int> top_k = S.topKFrequent(nums, 6);
    print_vec(top_k);

    return 0;
}
