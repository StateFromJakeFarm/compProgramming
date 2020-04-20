#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_zeros = 0;
        long non_zero_prod = 1;
        for (int &x : nums) {
            if (x != 0) {
                non_zero_prod *= x;
            } else {
                num_zeros++;
                if (num_zeros > 1) break;
            }
        }

        for (int &x : nums) {
            if (num_zeros > 1) {
                x = 0;
            } else if (num_zeros == 1) {
                x = (x == 0) * non_zero_prod;
            } else {
                x = (non_zero_prod / x);
            }
        }

        return nums;
    }
};


int main() {
    vector<int> nums = {1, 2, 0, 3, 4};

    Solution s;
    for (int &x : s.productExceptSelf(nums)) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
