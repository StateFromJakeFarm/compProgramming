#include<iostream>

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for(int i=0; i<numCases; i++) {
        int cycles;
        cin >> cycles;

        int height = 1;
        for(int j=0; j<cycles; j++) {
            if(j % 2 == 0) {
                height *= 2;
            } else {
                height += 1;
            }
        }

        cout << height << endl;
    }
}
