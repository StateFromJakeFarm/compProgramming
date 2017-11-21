#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Get our input string
    string x;
    getline(cin, x);
    int n = (int)x.length();

    // 2-D matrix to hold our palindrome info (dynamic structure)
    vector< vector<bool> > P(n);

    // Seed our matrix with the length-1 palindromes
    for(int i=0; i<n; i++)
        P[i][i] = true;

    // Populate P matrix and check if every palindrome is odd
    int j;
    for(int q=1; q<n; q++) {
        for(int i=0; i<n-q; i++) {
            j = i + q;

            if(x[i] == x[j]) {
                // Characters at different positions in string are the same,
                // this COULD be a palindrome...

                if(j == i+1 || P[i+1][j-1]) {
                    // Found a palindrome cut; record in matrix and check odd
                    if((j-i+1) % 2 == 0) {
                        // Palindrome is not odd!
                        cout << "Or not." << endl;
                        return 0;
                    }

                    P[i][j] = true;
                }
            }
        }
    }

    cout << "Odd." << endl;

    return 0;
}
