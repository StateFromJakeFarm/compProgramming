#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int next_dir(int &direction) {
        if (direction == 3)
            return 0;
        return direction + 1;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int total = r * c;
        int seen = 0;

        int i = 0;
        int j = 0;
        int i_incr[4] = {0, 1, 0, -1};
        int j_incr[4] = {1, 0, -1, 0};
        int dir = 0;

        vector<int> out;
        while (seen < total) {
            if (i < 0 || i >= r || j < 0 || j >= c || matrix[i][j] == INT_MAX) {
                i -= i_incr[dir];
                j -= j_incr[dir];
                dir = next_dir(dir);
                i += i_incr[dir];
                j += j_incr[dir];
            }

            out.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;
            i += i_incr[dir];
            j += j_incr[dir];
            seen++;
        }

        return out;
    }
};

void print(vector<int> out) {
    for (auto &n : out) {
        cout << n << ' ';
    }
    cout << endl;
}

int main() {
    Solution S;

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    auto out = S.spiralOrder(matrix);
    print(out);

    return 0;
}
