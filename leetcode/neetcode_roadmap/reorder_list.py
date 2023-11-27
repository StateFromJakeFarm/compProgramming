from math import ceil
from collections import deque


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        parents = deque([None])
        node = head
        n = 1
        while node.next:
            n += 1
            parents.append(node)
            node = node.next

        l = head
        r = node
        for i in range(ceil(n/2) - 1):
            l_n = l.next
            l.next = r
            r.next = l_n

            r = parents[-1]
            r.next = None
            parents.pop()

            l = l_n
