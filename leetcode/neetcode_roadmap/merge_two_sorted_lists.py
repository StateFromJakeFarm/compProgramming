# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self):
        self.head = None
        self.tail = None


    def add(self, val):
        if self.head is None:
            self.head = ListNode(val=val)
            self.tail = self.head
        else:
            self.tail.next = ListNode(val=val)
            self.tail = self.tail.next


    def mergeTwoLists(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        while l1 or l2:
            if l1 and l2:
                if l1.val < l2.val:
                    self.add(l1.val)
                    l1 = l1.next
                else:
                    self.add(l2.val)
                    l2 = l2.next
            elif l1:
                self.add(l1.val)
                l1 = l1.next
            else:
                self.add(l2.val)
                l2 = l2.next

        return self.head
