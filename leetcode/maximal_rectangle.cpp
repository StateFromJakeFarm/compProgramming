#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print(vector<vector<int>> &vv) {
    for (auto &v : vv) {
        for (int &i : v) {
            cout << i << ' ';
        }
        cout << endl;
    }
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> U(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> L(matrix.size(), vector<int>(matrix[0].size(), 0));


        for (unsigned i=0; i<matrix.size(); i++) {
            for (unsigned j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    if (i > 0) {
                        // There is a row above us, so longest strip going upwards
                        // can be increased with this square
                        U[i][j] = U[i-1][j] + 1;
                    } else {
                        U[i][j] = 1;
                    }

                    if (j > 0) {
                        // There is a row to the left of us, so longest strip
                        // going to the left can be increased with this square
                        L[i][j] = L[i][j-1] + 1;
                    } else {
                        L[i][j] = 1;
                    }
                } else {
                    // Tallest and longest strips of ones that contain a zero
                    // can't exist, so just set both to zero size
                    U[i][j] = 0;
                    L[i][j] = 0;
                }
            }
        }

        int largest_overall = 0;
        int largest_ending_with_this_square;
        int min_left_strip_above_me;
        int min_vert_strip_left_of_me;
        for (unsigned i=0; i<matrix.size(); i++) {
            for (unsigned j=0; j<matrix[i].size(); j++) {
                // There are U[i][j] leftward "strips" above us, but their sizes could be
                // different.  The shortest strip is the width of the rectangle that spans
                // all strips above us.
                min_left_strip_above_me = INT_MAX;
                largest_ending_with_this_square = 0;
                for (int k=0; k<U[i][j]; k++) {
                    min_left_strip_above_me = min(L[i-k][j], min_left_strip_above_me);
                    largest_ending_with_this_square = max((k+1) * min_left_strip_above_me, largest_ending_with_this_square);
                }

                // There are L[i][j] vertical "strips" above us, but their sizes could be
                // different.  The shortest strip is the height of the rectangle that spans
                // all strips to the left of us.
                min_vert_strip_left_of_me = INT_MAX;
                for (int k=0; k<L[i][j]; k++) {
                    min_vert_strip_left_of_me = min(U[i][j-k], min_vert_strip_left_of_me);
                    largest_ending_with_this_square = max((k+1) * min_vert_strip_left_of_me, largest_ending_with_this_square);
                }

                largest_overall = max(largest_ending_with_this_square, largest_overall);
            }
        }

        return largest_overall;
    }
};

int main() {
    vector<vector<char>> input = {
        {'0','0','1','0'},
        {'0','0','1','0'},
        {'0','0','1','0'},
        {'0','0','1','1'},
        {'0','1','1','1'},
        {'1','1','1','1'}
    };

    Solution S;
    cout << S.maximalRectangle(input) << endl;

    return 0;
}
