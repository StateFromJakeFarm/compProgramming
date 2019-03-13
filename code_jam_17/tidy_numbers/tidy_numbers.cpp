#include <iostream>
#include <vector>

using namespace std;

void print(const vector<char> &v) {
    for (unsigned i=0; i<v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
}

void print_last_tidy(string &N) {
    vector<char> v;
    int i;
    for (i=0; i<N.length(); i++) {
        v.push_back(N[i]);
    }

    int f = 0;
    for (i=0; i<v.size(); i++) {
        if (v[i] < v[i-1]) {
            v[f]--;
            for (int j=f+1; j<v.size(); j++) {
                v[j] = '9';
            }

            break;
        }

        if (v[f] != v[i]) {
            f = i;
        }
    }

    for (i=0; i<N.length(); i++) {
        if (i > 0 || v[i] != '0') {
            cout << v[i];
        }
    }
}

int main() {
    int T;
    string N;
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        cout << "Case #" << t << ": ";
        print_last_tidy(N);
        cout << endl;
    }

    return 0;
}
