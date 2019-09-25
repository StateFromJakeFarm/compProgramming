#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unsigned longest = 0;

            char c;
            unordered_map<char, int> *seen = new unordered_map<char, int>;
            for (unsigned i=0; i<s.size(); i++) {
                c = s[i];
                if (seen->find(c) == seen->end()) {
                    seen->insert( make_pair(c, i) );
                } else {
                    i = seen->at(c);
                    longest = max(longest, (unsigned)seen->size());
                    delete seen;
                    seen = new unordered_map<char, int>;
                }
            }

            longest = max(longest, (unsigned)seen->size());
            delete seen;

            return longest;
        }
};

int main() {
    Solution S;

    string q = "dvdf";

    cout << S.lengthOfLongestSubstring(q) << endl;

    return 0;
}
