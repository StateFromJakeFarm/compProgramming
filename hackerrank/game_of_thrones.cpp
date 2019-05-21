#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> counts(26);
    for (char c : s) {
        counts[c - 'a']++;
    }

    bool foundOdd = false;
    for (int c : counts) {
        if (c % 2) {
            if (foundOdd) {
                cout << "NO" << endl;
                return 0;
            } else {
                foundOdd = true;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
