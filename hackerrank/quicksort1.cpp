#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> & arr) {
    for (int i=0; i<(int)arr.size(); i++)
        cout << arr[i] << ' ';
}

void meme(vector<int> & arr, vector<int> & left, vector<int> & right) {
    int pivot = arr[0];
    for (int i=1; i<(int)arr.size(); i++) {
        if (arr[i] <= pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }

    print(left);
    cout << pivot << ' ';
    print(right);
    cout << endl;
}

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i=0; i<size; i++)
        cin >> arr[i];

    vector<int> left, right;
    meme(arr, left, right);

    return 0;
}
