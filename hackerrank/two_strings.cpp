#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool shareSubstring(const string &s1, const string &s2) {
    vector<bool> seen(26);
    for (auto c : s1) {
        seen[c - 'a'] = true;
    }

    for (auto c : s2) {
        if (seen[c - 'a']) {
            return true;
        }
    }

    return false;
}

int main() {
    int p;
    string s1, s2;

    cin >> p;
    cin.ignore();
    for (int i=0; i<p; i++) {
        getline(cin, s1);
        getline(cin, s2);

        if (shareSubstring(s1, s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
