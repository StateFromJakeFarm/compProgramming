#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int count = 1;
    while(true) {
        int N, R;
        cin >> N >> R;
        if(N == 0 && R ==0)
            break;

        // create graph
        int widest[N][N];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                if(i == j)
                    widest[i][j] = 0;
                else
                    widest[i][j] = INT_MIN;
        }

        // fill graph with road weights
        int c1, c2, p;
        for(int r=0; r<R; r++) {
            cin >> c1 >> c2 >> p;

            widest[c1-1][c2-1] = p;
            widest[c2-1][c1-1] = p;
        }

        // source and destination cities
        cin >> c1 >> c2 >> p;
        --c1;
        --c2;

        // edge case where cities are the same
        if(c1 == c2) {
            cout << "Scenario #" << count << endl;
            cout << "Minimum Number of Trips = " << 0 << endl;
            cout << endl;
            ++count;
            continue;
        }

        // Floyd-Warshall to get widest paths
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    int minWeight = min(widest[i][k], widest[k][j]);
                    if(widest[i][j] < minWeight) {
                        widest[i][j] = minWeight;
                        widest[j][i] = minWeight;
                    }
                }
            }
        }

        // calculate number of trips
        double maxFlow = widest[c1][c2]-1;
        int trips = ceil(p/maxFlow);
        cout << "Scenario #" << count << endl;
        cout << "Minimum Number of Trips = " << trips << endl;
        cout << endl;

        ++count;
    }

    return 0;
}
