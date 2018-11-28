#include <iostream>
#include <algorithm>

using namespace std;

long three_way_max(long a, long b, long c) {
    a = max(a, b);
    return max(a, c);
}

int main() {
    int T, N;
    cin >> T;

    for (int t=0; t<T; t++) {
        cin >> N;
        // Store reversed version of array because we consider elements in the
        // stack from the bottom-up
        long arr[N];
        for (int n=0; n<N; n++) {
            cin >> arr[N-n-1];
        }

        // Record the sum of all elements up to this position (total score available)
        // in the remainder of the stack
        long sum_arr[N];
        sum_arr[0] = arr[0];
        for (int i=1; i<N; i++) {
            sum_arr[i] = sum_arr[i-1] + arr[i];
        }

        long D[N];
        for (int i=0; i<N; i++) {
            if (i < 3) {
                // If <= 3 elements left, best move is always to take all of them
                D[i] = sum_arr[i];
            } else {
                D[i] = three_way_max(
                    sum_arr[i] - D[i-1], // We take top element
                    sum_arr[i] - D[i-2], // We take top 2 elements
                    sum_arr[i] - D[i-3]  // We take top 3 elements
                );
            }
        }

        cout << D[N-1] << endl;
    }

    return 0;
}
