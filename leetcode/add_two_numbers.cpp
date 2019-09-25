/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *root = NULL;

        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int res;
            int overflow = 0;
            ListNode *cur = root;
            while (l1 || l2 || overflow) {
                // determine sum of digits at this position
                res = 0;
                if (l1 && l2) {
                    // Both numbers have a digit here
                    res = l1->val + l2->val;
                } else if (l1) {
                    // Only first number has digit here
                    res = l1->val;
                } else if (l2) {
                    // Only second number has digit here
                    res = l2->val;
                }
                res += overflow;

                if (res > 9) {
                    // Overflow occurred
                    overflow = 1;
                    res -= 10;
                } else {
                    // No overflow occurred
                    overflow = 0;
                }

                // Add this position to resultant list
                if (!cur) {
                    cur = new ListNode(res);
                    root = cur;
                } else {
                    cur->next = new ListNode(res);
                    cur = cur->next;
                }

                // Iterate
                if (l1) {
                    l1 = l1->next;
                }
                if (l2) {
                    l2 = l2->next;
                }
            }

            return root;
        }
};
