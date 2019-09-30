#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int num_rows) {
        int i = 0;
        string result = s;

        int gap = num_rows + (num_rows-2);
        if (gap <= 0) {
            return s;
        }

        for (int row=0; row<num_rows; row++) {
            for (int cur=row; cur<(int)s.length(); cur+=gap) {
                result[i] = s[cur];
                i++;

                if (row > 0 && row < num_rows-1 && (cur + gap - row*2) < (int)s.length()) {
                    result[i] = s[cur + gap - row*2];
                    i++;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "PAYPALISHIRING";

    cout << sol.convert("ABC", 3) << endl;

    return 0;
}
