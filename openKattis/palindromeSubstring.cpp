#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string getSubStr(const string & x, int s, int t) {
    string subStr = "";
    for(int i=s; i<=t; i++)
        subStr += x[i];

    return subStr;
}

int main() {
    // Get our input strings
    string x;
    while(getline(cin, x)) {
        int n = (int)x.length();

        // 2-D matrix to hold our palindrome info (dynamic structure)
        vector< vector<bool> > P(n);
        for(int i=0; i<n; i++)
            P[i].resize(n);

        // Seed our matrix with the length-1 palindromes
        for(int i=0; i<n; i++)
            P[i][i] = true;

        // Keep track of which palindromes we've seen so we don't repeat any
        vector<string> unique;

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
                        P[i][j] = true;

                        if(i != j) {
                            string palindromeStr = getSubStr(x, i, j);
                            if(find(unique.begin(), unique.end(), palindromeStr) == unique.end()) {
                                // This is a new palindrome, add to our list
                                unique.push_back(palindromeStr);
                            }
                        }
                    }
                }
            }
        }

        // Print the sorted palindromes
        sort(unique.begin(), unique.end());
        for(int i=0; i<(int)unique.size(); i++)
            cout << unique[i] << endl;
        cout << endl;
    }

    return 0;
}
