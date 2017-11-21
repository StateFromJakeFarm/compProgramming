#include <iostream>
#include <climits>

using namespace std;

int main() {
    long int T;
    cin >> T;
    for(long int t=0; t<T; t++) {

        long int N;
        cin >> N;

        long int prices[N];
        for(long int n=0; n<N; n++) {
            cin >> prices[n];
        }

        long int stockMax = 0;
        long int bestPrice = INT_MIN;
        for(long int n=N-1; n>=0; n--) {
            if(prices[n] > bestPrice)
                bestPrice = prices[n];

            if(prices[n] < bestPrice)
                stockMax += bestPrice - prices[n];
        }
        cout << stockMax << endl;
    }

    return 0;
}
