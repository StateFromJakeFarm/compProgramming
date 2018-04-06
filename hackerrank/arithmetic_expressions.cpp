#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool swap_ops(int *list, const int &n, const int &i, const long &cur_val, stack<string> &ans) {
    if (i == n) // Past last element
        return false;

    if (i == n-1) { // Last element, need to check if divisible by 101
        if ((cur_val - list[i]) % 101 == 0) {
            ans.push(to_string(list[i]));
            ans.push("-");
            return true;
        } else if ((cur_val * list[i]) % 101 == 0) {
            ans.push(to_string(list[i]));
            ans.push("*");
            return true;
        } else if ((cur_val + list[i]) % 101 == 0) {
            ans.push(to_string(list[i]));
            ans.push("+");
            return true;
        }
    } else { // "In-between" element
        if (swap_ops(list, n, i+1, cur_val-list[i], ans)) {
            ans.push(to_string(list[i]));
            ans.push("-");
            return true;
        } else if (swap_ops(list, n, i+1, cur_val*list[i], ans)) {
            ans.push(to_string(list[i]));
            ans.push("*");
            return true;
        } else if (swap_ops(list, n, i+1, cur_val+list[i], ans)) {
            ans.push(to_string(list[i]));
            ans.push("+");
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    int list[n];
    for (int i=0; i<n; i++)
        cin >> list[i];

    stack<string> ans;
    swap_ops(list, n, 1, list[0], ans);

    // Print answer
    cout << list[0];
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;

    return 0;
}
