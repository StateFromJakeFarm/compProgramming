#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> array;
    int num;
    for(int i=0; i<n; i++) {
        cin >> num;
        array.push_back(num);
    }

    for(int i=0; i<k; i++) {
        array.insert(array.begin(), array[n-1]);
        array.pop_back();
    }   

    int m;
    for(int i=0; i<q; i++) {
        cin >> m;
        cout << array[m] << endl;
    }   

    return 0;
}

