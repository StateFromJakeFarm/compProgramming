#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;

    vector<long> arr(n);

    for (long i=0; i<n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    long num = 0;
    long i, j;
    i = 0; j = 1;
    while (i < n && j < n) {
        if (i == j)
            j++;
        else {
            long diff = arr[j] - arr[i];
            if (diff == k) {
                num++;
                i++; j++;
            } else if (diff < k) {
                j++;
            } else {
                i++;
            }
        }
    }

    cout << num << endl;

    return 0;
}
