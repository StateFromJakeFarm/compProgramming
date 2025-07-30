# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def plist(head):
    cur = head
    while cur is not None:
        print(cur.val)
        cur = cur.next


class Solution:
    def reverseKGroup(self, head, k: int):
        if k == 1:
            return head

        start_parent = None
        arr = [None for _ in range(k)]
        cur = head
        i = 0
        while cur is not None:
            arr[i % k] = cur
            i += 1

            if i % k == 0:
                for l in range(k // 2):
                    r = k - l - 1

                    # l's parent points to r
                    if l == 0:
                        if start_parent is not None:
                            start_parent.next = arr[r]
                    else:
                        arr[l - 1].next = arr[r]

                    # r takes l's child
                    temp = arr[r].next
                    if l == (r - 1):
                        # l is r's parent
                        arr[r].next = arr[l]
                    else:
                        arr[r].next = arr[l+1]

                    # l takes r's child
                    arr[l].next = temp

                    if (r - l) > 1:
                        # r's parent IS NOT l
                        arr[r-1].next = arr[l]

                    # Swap array positions
                    temp = arr[l]
                    arr[l] = arr[r]
                    arr[r] = temp


                if start_parent is None:
                    # This is the first group we've switched, so it's start is now the new head
                    head = arr[0]

                start_parent = arr[-1]
                cur = start_parent.next
            else:
                cur = cur.next

        return head


l = [1,2]
k = 2

head = ListNode(l[0], None)

cur = head
for v in l[1:]:
    cur.next = ListNode(v, None)
    cur = cur.next


S = Solution()
head = S.reverseKGroup(head, k)


plist(head)
