#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
    char action;
    string input;
    cin >> action >> input;

    if (action == 'D') {
        char last = '0';
        string occ;
        for (int i=0; i<(int)input.length(); i++) {
            if (isdigit(input[i])) {
                occ += input[i];
            } else {
                if (last != '0') {
                    for (int j=0; j<stoi(occ); j++) {
                        cout << last;
                    }
                    occ = "";
                }

                last = input[i];
            }
        }
        for (int j=0; j<stoi(occ); j++) {
            cout << last;
        }

        cout << endl;
    } else {
        char last = '0';
        char cur;
        int n = 0;
        for (int i=0; i<(int)input.length(); i++) {
            cur = input[i];
            if (cur != last) {
                if (last != '0') {
                    cout << last << n;
                }
                last = cur;
                n = 1;
            } else {
                n++;
            }
        }
        cout << last << n;
        cout << endl;
    }

    return 0;
}
