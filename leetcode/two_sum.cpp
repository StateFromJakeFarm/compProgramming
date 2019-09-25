#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> indices;

            for (int i=0; i<(int)nums.size(); i++) {
                if (indices.find(target - nums[i]) != indices.end()) {
                    vector<int> to_return = {indices[ target - nums[i] ], i};
                    return to_return;
                }

                indices[nums[i]] = i;
            }


            vector<int> to_return;
            return to_return;
        }
};

int main() {
    Solution S;

    vector<int> in = {2, 7, 11, 15};
    for (int i : S.twoSum(in, 9)) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
