# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        nth_prev = None
        nth = None
        count = 0
        cur = head
        while cur:
            count += 1
            if count >= n:
                if nth is None:
                    nth = head
                else:
                    nth_prev = nth
                    nth = nth.next

            cur = cur.next

        if nth_prev:
            nth_prev.next = nth.next
        if nth == head:
            head = head.next

        return head
