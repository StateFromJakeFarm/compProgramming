#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, bool> unique;

    int numUniques = 0;
    int cur;
    for(int i=0; i<10; i++) {
        cin >> cur;
        cur %= 42;
        if (unique.find(cur) == unique.end()) {
            unique[cur] = true;
            ++numUniques;
        }
    }

    cout << numUniques << endl;

    return 0;
}
