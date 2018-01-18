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
        for (int i=0; i<P.length()-1; i++)
            table[i].resize(P.length()-1);

        int max_for_S_equal_zero = 0;
        for (int i=0; i<table.size(); i++) {
            for (int j=0; j<table.size(); j++) {
                if (P[i] == Q[j]) {
                    if (i-1 < 0 || j-1 < 0) {
                        table[i][j] = 1;
                    } else {
                        table[i][j] = table[i-1][j-1] + 1;
                    }

                    max_for_S_equal_zero = max(max_for_S_equal_zero, table[i][j]);
                }
            }
        }

        if (S == 0) {
            cout << max_for_S_equal_zero << endl;
            continue;
        }

        int max_len = 0;
        // Upper-right through middle
        for (int d=0; d<table.size(); d++) {
            int len = 0;
            int diag_max = 0;
            int num_blank = 0;

            for (int i=table.size()-1-d; i>=0; i--) {
                int val = table[i][i+d];
                if (val == 0) {
                    if (num_blank == S) {
                        diag_max = max(diag_max, len);
                        len = 0;
                        num_blank = 0;
                    } else {
                        num_blank++;
                        len++;
                    }
                } else {
                    len += val;
                    i -= val;
                }

                diag_max = max(diag_max, len);
            }

            max_len = max(max_len, diag_max);
        }

        // Middle+1 through bottom-left
        for (int d=0; d<table.size(); d++) {
            int len = 0;
            int diag_max = 0;
            int num_blank = 0;

            for (int i=table.size()-1-d; i>=0; i--) {
                int val = table[i+d][i];
                if (val == 0) {
                    if (num_blank == S) {
                        diag_max = max(diag_max, len);
                        len = 0;
                        num_blank = 0;
                    } else {
                        num_blank++;
                        len++;
                    }
                } else {
                    len += val;
                    i -= val;
                }

                diag_max = max(diag_max, len);
            }

            max_len = max(max_len, diag_max);
        }
        cout << max_len << endl;
    }

    return 0;
}
