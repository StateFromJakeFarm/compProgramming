#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int array[n];
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        array[i] = num;
    }

    int l = -1;
    int r = -1;
    int lIndex = -1;
    int rIndex = -1;

    int cur;
    int prev = array[0];
    for(int i=1; i<n; i++) {
        cur = array[i];

        if(l == -1 && cur == prev-1) {
            lIndex = 0;
            l = prev;
            rIndex = i;
            r = cur;
        } else if(l == -1 && cur > prev+1) {
            lIndex = i;
            l = array[i];
        } else if(l != -1 && cur == prev-1) {
            rIndex = i;
            r = array[i];
        } else if(l != -1 && cur < prev-1) {
            cout << "no" << endl;
            return 0;
        } else if(l != -1 && cur != array[lIndex]+1) {
            cout << "no" << endl;
            return 0;
        }

        prev = cur;
    }

    if(rIndex - lIndex == 1) {
        cout << "swap ";
    } else {
        cout << "reverse ";
    }

    cout << lIndex+1 << " " << rIndex+1 << endl;

    return 0;
}








