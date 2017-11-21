#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Array to contain number of modulo value occurrences
    int mods[k];
    memset(mods, 0, sizeof(mods));

    int s;
    for(int i=0; i<n; i++) {
        cin >> s;
        // Increment occurrence of modulo (indexed by modulo value)
        ++mods[s % k];
    }

    int opt = 0;
    for(int i=0; i <= k/2; i++) {
        if(i == (k-i)%k)
            // Choose either 0 or 1 number perfectly-divisible by k (i == 0) OR
            // a number perfectly-divisible by half of k (i == k/2 && k % 2 == 0)
            opt += min(mods[i], 1);
        else
            opt += max(mods[i], mods[(k-i)%k]);
    }

    cout << opt << endl;

    return 0;
}
