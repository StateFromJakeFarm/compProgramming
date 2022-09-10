#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int longest = 0;
        int last_repeat_idx = -1;
        char cur;
        for (int i=0; i<(int)s.length(); i++) {
            cur = s[i];

            if (last_seen.find(cur) == last_seen.end()) {
                // First time seeing this character; record its position
                last_seen[cur] = i;
            } else {
                last_repeat_idx = max(last_repeat_idx, last_seen[cur]);
                last_seen[cur] = i;
            }

            longest = max(longest, (int)(i - last_repeat_idx));
        }

        return max(longest, (int)((s.length() - 1) - last_repeat_idx));
    }
};

int main() {
    Solution S;

    string s = "acbcafbc";

    cout << S.lengthOfLongestSubstring(s) << endl;

    return 0;
}
