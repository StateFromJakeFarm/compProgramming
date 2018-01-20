#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << arr[ceil(n/2)] << endl;

    return 0;
}
