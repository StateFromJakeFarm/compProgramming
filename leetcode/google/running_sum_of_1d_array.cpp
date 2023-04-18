#include <bits/stdc++.h>

using namespace std;


void print_vec(vector<int>& vec) {
    for (auto &v : vec) {
        cout << v << ' ';
    }
    cout << endl;
}


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> out;
        out.resize(nums.size());
        out[0] = nums[0];
        for (unsigned i=1; i<nums.size(); i++) {
            out[i] = nums[i] + out[i-1];
        }

        return out;
    }
};


int main() {
    Solution S;
    vector<int> in = {3,1,2,10,1};
    auto vec = S.runningSum(in);
    print_vec(vec);

    return 0;
}
