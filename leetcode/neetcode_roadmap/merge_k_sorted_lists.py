# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, curs):
        new_head = None
        new_cur = None

        lists_not_empty = True
        while lists_not_empty:
            lists_not_empty = False

            smallest = None
            smallest_idx = -1
            for i, cur in enumerate(curs):
                if cur is not None:
                    lists_not_empty = True
                else:
                    continue

                if smallest is None or cur.val < smallest.val:
                    smallest = cur
                    smallest_idx = i

            if lists_not_empty:
                curs[smallest_idx] = smallest.next

                if new_cur is None:
                    new_head = smallest
                    new_cur = smallest
                else:
                    new_cur.next = smallest

                new_cur = smallest
                new_cur.next = None

        return new_head
