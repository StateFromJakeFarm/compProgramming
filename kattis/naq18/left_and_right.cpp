#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int num_opposite(string &dirs, const int i, const char &c) {
    int n = 0;
    for (unsigned j=i+1; j<dirs.length(); j++) {
        if (dirs[j] == c) {
            break;
        } else {
            n++;
        }
    }

    return n;
}

int main() {
    int n;
    string dirs;
    cin >> n >> dirs;

    int pos = 1;
    char cur;
    int furthest = -1;
    for (unsigned i=0; i<dirs.length(); i++) {
        cur = dirs[i];

        // Number of characters after this one which are NOT the same direction as the
        // current character
        int num_op = num_opposite(dirs, i, dirs[i]);

        if (i == 0) {
            // First element determines where we start
            if (cur == 'L') {
                // If we go left first, we must be starting somewhere in the middle
                pos += num_opposite(dirs, -1, 'R');
                furthest = max(furthest, pos);
            }

            cout << pos << endl;
        }

        if (cur == 'R') {
            // If we're going right, find out how far to the left we need to go AFTER making
            // this move to the right
            furthest = max(furthest, pos);
            pos = furthest + num_op + 1;
            furthest = max(furthest, pos);

            cout << pos << endl;
        } else {
            // Go to next house on left
            pos--;
            cout << pos << endl;
        }
    }

    return 0;
}
