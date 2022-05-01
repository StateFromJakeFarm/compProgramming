#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

void print(vector<int> v) {
    for (auto &i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> vv) {
    for (auto &v : vv) {
        print(v);
    }
}


// Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int &i : nums) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 1;
            } else {
                counts[i]++;
            }
        }

        vector<int> keys;
        for (auto &it : counts) {
            keys.push_back(it.first);
        }
        sort(keys.begin(), keys.end());

        vector<vector<int>> triplets;
        int first, second, third;
        unsigned j;
        for (unsigned i=0; i<keys.size(); i++) {
            first = keys[i];

            if (counts[first] > 1) {
                j = i;
            } else {
                j = i+1;
            }
            for (j; j<keys.size(); j++) {
                second = keys[j];
                third = -1 * (first + second);
                if (second == third && counts[second] < 2) continue;
                if (first == 0 && second == 0 && counts[0] < 3) continue;

                if (counts.find(third) != counts.end() && first <= second && second <= third) {
                    triplets.push_back({first, second, third});
                }
            }
        }

        return triplets;
    }
};


int main() {
    Solution S;

    vector<int> v = {-1,0,1,2,-1,-4};
    print2d(S.threeSum(v));

    return 0;
}
