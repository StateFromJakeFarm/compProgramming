#include <iostream>
#include <string>
#include <map>

using namespace std;

long long subStrSum(map<string, long long> & dict, string S, long long depth, int whichChild) {
    auto it = dict.find(S);
    if(it != dict.end()) {
        return dict[S];
    }

    long long val = stold(S);
    long long len = S.length();

    if(len == 1)
        return val;

    if(whichChild == 0) {
        // Spawn first child
        string sub0 = S.substr(0, len-1);
        val += subStrSum(dict, sub0, depth+1, 0);
    }

    // Spawn second child
    string sub1 = S.substr(1, len-1);
    val += subStrSum(dict, sub1, depth+1, 1);

    dict[S] = val;
    return val;
}

int main() {
    string N;
    getline(cin, N);

    map<string, long long> dict;
    cout << to_string((long long)subStrSum(dict, N, 0, 0) % 1000000007) << endl;

    return 0;
}
