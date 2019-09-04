#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int hourglass_sum(const vector< vector<int> > &grid, int i, int j) {
    return grid[i][j] + grid[i][j+1] + grid[i][j+2] +
                        grid[i+1][j+1] +
           grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
}

int main() {
    vector< vector<int> > grid(6);
    for (int i=0; i<6; i++) {
        grid[i].resize(6);
        for (int j=0; j<6; j++) {
            cin >> grid[i][j];
        }
    }

    int max_sum = INT_MIN;
    for (int i=0; i<=3; i++) {
        for (int j=0; j<=3; j++) {
            max_sum = max(max_sum, hourglass_sum(grid, i, j));
        }
    }

    cout << max_sum << endl;

    return 0;
}
