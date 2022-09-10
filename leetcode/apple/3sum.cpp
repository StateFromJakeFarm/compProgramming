#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        int i, j, k, sum;
        for (i=0; i<(int)nums.size(); i) {
            // nums[i] will be included in this triplet, so target becomes 0 - nums[i]
            j = i+1;
            k = nums.size() - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    if (j < nums.size() - 1) {
                        while(nums[j] == nums[++j]) {}
                    } else {
                        j++;
                    }
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }

            if (i < nums.size() - 1) {
                while(nums[i] == nums[++i]) {}
            } else {
                i++;
            }
        }

        return triplets;
    }
};

int main() {
    Solution S;

    vector<int> nums = {0,0,0,0};
    //vector<int> nums = {-1,0,1,2,-1,-4};
    for (auto &t : S.threeSum(nums)) {
        for (int &n : t) {
            cout << n << ' ';
        }
        cout << endl;
    }

    return 0;
}
