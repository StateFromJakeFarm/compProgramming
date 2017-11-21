#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    int numWords = 1;
    int i = 0;
    while(s[i]) {
        if(isupper(s[i]))
            ++numWords;

        ++i;
    }

    cout << numWords << endl;

    return 0;
}
