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
        P = PQ.substr(1, space_index-1);
        Q = PQ.substr(space_index+1, PQ.length()-1);

        vector< vector<int> > table(P.length());
        for (int i=0; i<P.length(); i++)
            table[i].resize(P.length());

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
        for (int d=0; d<table.size(); d++) {
            for (int j=table.size()-1-d; j>=0; j--) {
                if (table[j][j+d] == 0)
                    continue;

                int len = 0;
                int num_blank = 0;
                for (int i=j; i>=0; i--) {
                    int val = table[i][i+d];
                    if (val == 0) {
                        if (num_blank == S) {
                            max_len = max(max_len, len);

                            len = 0;
                            num_blank = 0;
                        } else {
                            num_blank++;
                            len++;
                        }
                    } else {
                        len += val;
                        i -= val-1;
                    }

                    max_len = max(max_len, len);
                }
            }
        }

        for (int d=0; d<table.size(); d++) {
            for (int j=table.size()-1-d; j>=0; j--) {
                if (table[j+d][j] == 0)
                    continue;

                int len = 0;
                int num_blank = 0;
                for (int i=j; i>=0; i--) {
                    int val = table[i+d][i];
                    if (val == 0) {
                        if (num_blank == S) {
                            max_len = max(max_len, len);

                            len = 0;
                            num_blank = 0;
                        } else {
                            num_blank++;
                            len++;
                        }
                    } else {
                        len += val;
                        i -= val-1;
                    }

                    max_len = max(max_len, len);
                }
            }
        }

        cout << max_len << endl;
    }

    return 0;
}
