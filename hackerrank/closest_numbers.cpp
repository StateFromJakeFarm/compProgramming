#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> min_pairs;
    int min_distance = INT_MAX;
    int cur_dist;
    for (int i=0; i<n-1; i++) {
        cur_dist = abs(arr[i+1] - arr[i]);
        min_distance = min(min_distance, cur_dist);
    }

    for (int i=0; i<n-1; i++) {
        cur_dist = abs(arr[i+1] - arr[i]);
        if (cur_dist <= min_distance) {
            min_pairs.push_back(arr[i]);
            min_pairs.push_back(arr[i+1]);
        }
    }

    for (int i=0; i<(int)min_pairs.size(); i++)
        cout << min_pairs[i] << ' ';
    cout << endl;

    return 0;
}
