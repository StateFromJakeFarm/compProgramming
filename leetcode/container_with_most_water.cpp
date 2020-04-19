#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0;
        int j = a.size() - 1;
        int best = INT_MIN;
        while (i != j) {
            best = max( min(a[i], a[j]) * (j - i), best);

            if (a[i] < a[j] || a[i] == a[j]) {
                i++;
            } else {
                // a[i] > a[j]
                j--;
            }
        }

        return best;
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 1, 1, 1, 1, 2, 3, 4};

    Solution s;
    cout << s.maxArea(a) << endl;

    return 0;
}
