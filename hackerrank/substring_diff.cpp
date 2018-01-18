#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T, S;
    string PQ, P, Q;
    cin >> T;

    for (int t=0; t<T; t++) {
        cin >> S;
        getline(cin, PQ);

        int space_index = PQ.length()/2;
        P = PQ.substr(1, space_index);
        Q = PQ.substr(space_index+1, PQ.length()-1);

        vector< vector<int> > table(P.length()-1);
        for (int i=0; i<P.length(); i++)
            table[i].resize(P.length()-1);

        for (int i=0; i<P.length(); i++) {
            for (int j=0; j<P.length(); j++) {
                if (P[i] == Q[j]) {
                    if (i-1 < 0 || j-1 < 0)
                        table[i][j] = 1;
                    else
                        table[i][j] = table[i-1][j-1] + 1;
                }
            }
        }

        for (int i=0; i<table.size(); i++) {
            for (int j=0; j<table.size(); j++)
                cout << table[i][j] << ' ';
            cout << endl;
        }

        int max_len = 0;
        // Upper-right through middle
        for (int d=0; d<table.size(); d++) {
            int len = 0;
            int diag_max = 0;
            int num_blank = 0;

            for (int i=table.size()-1; i>=0; i--) {
cout << d << ": " << i << ", " << i-d << endl;
                int val = table[i][i+d];
            }
        }
        cout << max_len << endl;

        // Middle+1 through bottom-left
    }

    return 0;
}
