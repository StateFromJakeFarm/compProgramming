#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool len_then_lexicographic(const string & str1, const string & str2) {
    if (str1.length() == str2.length()) {
        return str1 < str2;
    } else {
        return str1.length() < str2.length();
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> unsorted(n);
    for (int i=0; i<n; i++)
        cin >> unsorted[i];

    sort(unsorted.begin(), unsorted.end(), len_then_lexicographic);

    for (int i=0; i<n; i++)
        cout << unsorted[i] << endl;

    return 0;
}
