#include <iostream>
#include <string>

using namespace std;

int main() {
    int letterHeights[26];

    int heightVal;
    for(int i=0; i<26; i++) {
        cin >> heightVal;
        letterHeights[i] = heightVal;
    }

    string word;
    cin >> word;

    int max = 0;
    for(int i=0; i<word.length(); i++) {
        int letterIndex = int(word[i]) - 97;
        int letterHeight = letterHeights[letterIndex];
        if(letterHeight > max)
            max = letterHeight;
    }

    cout << max*word.length() << endl;

    return 0;
}
