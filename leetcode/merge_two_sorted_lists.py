class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def __init__(self):
        self.head = None
        self.tail = None


    def append(self, val):
        if self.head is None:
            self.head = ListNode(val, None)
            self.tail = self.head
        else:
            new = ListNode(val, None)
            self.tail.next = new
            self.tail = new


    def mergeTwoLists(self, p1, p2):
        while (p1 is not None) and (p2 is not None):
            if p1.val < p2.val:
                self.append(p1.val)
                p1 = p1.next
            else:
                self.append(p2.val)
                p2 = p2.next

        while p1 is not None:
            self.append(p1.val)
            p1 = p1.next

        while p2 is not None:
            self.append(p2.val)
            p2 = p2.next

        return self.head


list1 = []
list2 = []

prev = None
node1 = None
for x in reversed(list1):
    node1 = ListNode(val=x, next=prev)
    prev = node1

prev = None
node2 = None
for x in reversed(list2):
    node2 = ListNode(val=x, next=prev)
    prev = node2

def plist(node):
    x = node
    while x is not None:
        print(x.val, end=' ')
        x = x.next

    print()

plist(node1)
plist(node2)


S = Solution()
plist(S.mergeTwoLists(node1, node2))
