#include <iostream>
#include <vector>

using namespace std;

int get_insertion_index(const vector<unsigned int> &s, const unsigned int &a) {
    int greater = 0;
    int lower   = (int)s.size() - 1;
    int mid     = (greater + lower) / 2;

    while (mid < (int)s.size() && mid >= 0 && greater < lower) {
        if (s[mid] > a) {
            greater = mid + 1;
        } else if (s[mid] < a) {
            lower = mid;
        } else {
            return mid;
        }

        mid = (greater + lower) / 2;
    }

    if (a < s[mid]) {
        return greater + 1;
    }

    return greater;
}

int main() {
    int n, m;

    // Get unique scores in decreasing order
    cin >> n;
    vector<unsigned int> s;
    unsigned int last_seen, cur = -1;
    for (int i=0; i<n; i++) {
        cin >> cur;
        if (last_seen != cur) {
            s.push_back(cur);
            last_seen = cur;
        }
    }

    // Binary search scores to see where each of Alice's scores falls
    cin >> m;
    unsigned int a;
    for (int i=0; i<m; i++) {
        cin >> a;
        cout << get_insertion_index(s, a) + 1 << endl;
    }

    return 0;
}
