#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

long stones(long piles, long size, const vector<long> &S, unordered_map<string, long> &dp) {
    if (dp.find(to_string(piles) + to_string(size)) != dp.end())
        return dp[to_string(piles) + to_string(size)];

    long max_moves = 0;
    for (unsigned int i=0; i<S.size(); i++) {
        long x = S[i];
        if (x >= size)
            break;

        if (size % x == 0)
            max_moves = max(max_moves, stones(piles*size/x, x, S, dp) + piles);
    }

    dp[to_string(piles) + to_string(size)] = max_moves;

    return max_moves;
}

int main() {
    int Q;
    cin >> Q;
    for (int q=0; q<Q; q++) {
        long n, m;
        cin >> n >> m;
        vector<long> S(m);
        for (int i=0; i<m; i++)
            cin >> S[i];

        sort(S.begin(), S.end());

        unordered_map<string, long> dp;

        cout << stones(1, n, S, dp) << endl;
    }

    return 0;
}
