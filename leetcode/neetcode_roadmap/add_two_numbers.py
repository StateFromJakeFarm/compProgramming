# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def __init__(self):
        self.head = None
        self.tail = None
        self.prev = None


    def add(self, new):
        if self.head is None:
            self.head = new
            self.tail = new
        else:
            self.tail.next = new
            self.tail = new


    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        while l1 or l2:
            if l1 and l2:
                res = l1.val + l2.val + carry
                if res > 9:
                    res -= 10
                    carry = 1
                else:
                    carry = 0

                l1 = l1.next
                l2 = l2.next
            elif l1:
                res = l1.val + carry
                if res > 9:
                    res -= 10
                    carry = 1
                else:
                    carry = 0
                l1 = l1.next
            else:
                res = l2.val + carry
                if res > 9:
                    res -= 10
                    carry = 1
                else:
                    carry = 0
                l2 = l2.next

            new = ListNode(res, None)
            self.add(new)

        if carry == 1:
            new = ListNode(1, None)
            self.add(new)

        return self.head
