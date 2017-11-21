#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string nFact;
    getline(cin, nFact);

    long int nFactLen = nFact.length();

    long unsigned int n = 2;
    if(nFactLen <= 3) {
        switch(stoi(nFact)) {
            case 1: n = 1; break;
            case 2: n = 2; break;
            case 6: n = 3; break;
            case 24: n = 4; break;
            case 120: n = 5; break;
            case 720: n = 6; break;
            default: return 1; break;
        };
    } else {
        float sum = 1;
        while(sum < nFactLen) {
            sum += log10(n);

            ++n;
        }

        --n;
    }

    cout << n << endl;

    return 0;
}
