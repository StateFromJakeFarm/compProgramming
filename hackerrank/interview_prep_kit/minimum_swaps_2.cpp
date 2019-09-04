#include <iostream>
#include <algorithm>

using namespace std;

int dfs_visit(const int* arr, int* visited, const int &n, const int &i) {
    if (visited[i]) {
        return 0;
    }
    visited[i] = 1;

    return 1 + dfs_visit(arr, visited, n, arr[i]);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    int visited[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr[i]--;

        visited[i] = 0;
    }

    int cycle_lens_sum = 0;
    for (int i=0; i<n; i++) {
        cycle_lens_sum += max(dfs_visit(arr, visited, n, i)-1, 0);
    }

    cout << cycle_lens_sum << endl;

    return 0;
}
