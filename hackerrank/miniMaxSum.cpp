#include <iostream>
#include <climits>

using namespace std;

int main() {
    long int min = LONG_MAX;
    long int max = 0;

    int minIndex, maxIndex;

    long int a[5];
    int num;
    for(int i=0; i<5; i++) {
        cin >> num;
        a[i] = num;
        if(num < min) {
            min = num;
            minIndex = i;
        }
        if(num > max) {
            max = num;
            maxIndex = i;
        }
    }

    long int minSum = 0;
    long int maxSum = 0;
    for(int i=0; i<5; i++) {
        if(i != minIndex)
            maxSum += a[i];
        if(i != maxIndex)
            minSum += a[i];
    }

    cout << minSum << " " << maxSum << endl;

    return 0;
}
