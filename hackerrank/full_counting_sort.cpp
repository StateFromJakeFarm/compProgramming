#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    unordered_map< int, vector< pair<bool, string> > > table;
    int n;
    cin >> n;

    vector<int> occurrences(100);

    int num;
    string str;
    for (int i=0; i<n; i++) {
        cin >> num;
        occurrences[num]++;

        cin >> str;

        bool is_first_half = false;
        if (i < n/2)
            is_first_half = true;

        table[num].push_back( make_pair(is_first_half, str) );
    }

    for (int i=0; i<100; i++) {
        for (int j=0; j<(int)table[i].size(); j++) {
            if (table[i][j].first)
                cout << "- ";
            else
                cout << table[i][j].second << ' ';
        }
    }
    cout << endl;

    return 0;
}
