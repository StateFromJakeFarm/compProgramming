#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> & arr) {
    for (int i=0; i<(int)arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i=0; i<size; i++)
        cin >> arr[i];

    for (int i=1; i<(int)arr.size(); i++) {
        for (int j=i; j>=0; j--) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            } else {
                break;
            }
        }
        print(arr);
    }

    return 0;
}
