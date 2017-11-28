#include <iostream>
#include <vector>

using namespace std;

int main() {
    double T;
    cin >> T;

    for(double t=0; t<T; t++) {
        double numCs, numE;
        cin >> numCs >> numE;
        if(numE == 0)
            numE = 1;

        vector<double> cs;

        double sumCs, sumE;
        sumCs = sumE = 0;

        double iq;
        for(double i=0; i<numCs+numE; i++) {
            cin >> iq;
            if(i < numCs) {
                sumCs += iq;
                cs.push_back(iq);
            } else
                sumE += iq;
        }

        double avgCs, avgE;
        avgCs = sumCs / numCs;
        avgE  = sumE  / numE;

        double numDingBats = 0;
        for(double i=0; i<numCs; i++) {
            if(avgE < cs[i] && cs[i] < avgCs)
                numDingBats++;
        }

        cout << numDingBats << endl;
    }

    return 0;
}
