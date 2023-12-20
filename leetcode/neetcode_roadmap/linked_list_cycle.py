# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            return False

        i = head
        j = head.next
        while i != j:
            i = i.next

            j = j.next
            if j is None:
                return False
            j = j.next
            if j is None:
                return False

        return True
