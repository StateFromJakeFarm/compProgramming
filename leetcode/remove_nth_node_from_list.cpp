#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* arr[30];

        int len = 0;
        while (head) {
            arr[len] = head;
            head = head->next;
            len++;
        }

        int i = len - n;
        if (i == 0) {
            if (len == 1) {
                return nullptr;
            }

            return arr[1];
        }

        arr[i-1]->next = arr[i]->next;

        return arr[0];
    }
};

int main() {
    Solution S;

    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode;
    ListNode *prev = head;
    ListNode *cur = head;
    for (int &i : v) {
        cur->val = i;
        cur->next = new ListNode;
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;

    head = S.removeNthFromEnd(head, 1);

    cur = head;
    while (cur) {
        cout << cur->val << endl;
        cur = cur->next;
    }

    return 0;
}
