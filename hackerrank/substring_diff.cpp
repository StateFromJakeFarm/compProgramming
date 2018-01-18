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

        vector< vector<int> > table(P.length());
        for (int i=0; i<P.length(); i++)
            table[i].resize(P.length());

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
        for (int i=0; i<P.length(); i++) {
            for (int j=0; j<P.length(); j++) {
                if (table[i][j] == true) {
                    int diff = 0;
                    int len  = 1;
                    int max_dim = max(i, j);
                    for (int q=1; max_dim+q<P.length(); q++) {
                        if (table[i+q][j+q] == true) {
                            len++;
                        } else if (diff < S) {
                            len++;
                            diff++;
                        } else {
                            break;
                        }
                    }

                    if (diff < S) {
                        int min_dim = min(i, j);
                        for (int q=1; diff<S && min_dim-q>=0; q++) {
                            if (table[i-q][j-q] == false) {
                                len++;
                                diff++;
                            } else {
                                break;
                            }
                        }
                    }

                    max_len = max(len, max_len);
                }
            }
        }

        cout << max(min(max_len, 1500), S) << endl;
    }

    return 0;
}
