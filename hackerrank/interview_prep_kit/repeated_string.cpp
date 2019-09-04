#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    long n;

    cin >> s >> n;
    vector<long> num_at_index(s.length(), 0);

    for (unsigned long i=0; i<s.length(); i++) {
        if (i > 0) {
            num_at_index[i] = num_at_index[i-1];
        }

        if (s[i] == 'a') {
            num_at_index[i]++;
        }
    }

    long occs = num_at_index[s.length()-1] * (n/s.length());
    if (n % s.length() > 0) {
        occs += num_at_index[n % s.length() - 1];
    }

    cout << occs << endl;

    return 0;
}
