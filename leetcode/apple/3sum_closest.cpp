#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long closest = INT_MAX;
        int cur_sum;
        unsigned i, lo, hi;
        for (i=0; i<nums.size(); i++) {
            lo = i+1;
            hi = nums.size() - 1;
            while (lo < hi) {
                cur_sum = nums[i] + nums[lo] + nums[hi];
                if (cur_sum == target) {
                    return target;
                }

                if (abs((long)target - cur_sum) < abs((long)target - closest)) {
                    closest = cur_sum;
                }

                if (cur_sum < target) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }

        return closest;
    }
};

int main() {
    Solution S;

    vector<int> nums = {1,1,1,1};
    int target = -100;

    cout << S.threeSumClosest(nums, target) << endl;

    return 0;
}
