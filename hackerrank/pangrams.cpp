#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    unordered_set <char> seen;

    int i = 0;
    char c;
    while (i < s.length() && seen.size() < 26) {
        c = tolower(s[i]);
        if (!c || c == ' ' || c == '\t' || c == '\n') {
            i++;
            continue;
        }

        if (seen.find(c) == seen.end()) {
            seen.insert(c);
        }

        i++;
    }

    if (seen.size() >= 26) {
        cout << "pangram" << endl;
    } else {
        cout << "not pangram" << endl;
    }

    return 0;
}
