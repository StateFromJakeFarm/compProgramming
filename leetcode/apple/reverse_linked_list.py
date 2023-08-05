class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def print_list(node):
    while node is not None:
        print(node.val)
        node = node.next


def create_list(arr):
    head = ListNode(arr[0])
    cur = head
    for x in arr[1:]:
        cur.next = ListNode(x)
        cur = cur.next

    return head


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return None

        p = None
        c = head
        n = head.next
        while True:
            c.next = p
            p = c
            c = n
            if c is None:
                break

            n = c.next

        return p

head = create_list([1, 2, 3, 4])

S = Solution()
rev_head = S.reverseList(head)

print_list(rev_head)
