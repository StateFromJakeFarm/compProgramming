#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        int half_index = -1;
        int val;
        for (int i=0; i<(int)nums.size(); i++) {
            val = nums[i];
            if (val*2 == target) {
                if (half_index != -1) {
                    return vector<int> {half_index, i};
                } else {
                    half_index = i;
                }
            }

            index[val] = i;
        }

        int comp;
        for (int i=0; i<(int)nums.size(); i++) {
            val = nums[i];
            comp = target - val;

            if ((index.find(comp) != index.end()) && (index[comp] != index[val])) {
                return vector<int> {i, index[comp]};
            }
        }

        return vector<int> {};
    }
};


int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    Solution S;
    vector<int> ans = S.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;

    return 0;
}
