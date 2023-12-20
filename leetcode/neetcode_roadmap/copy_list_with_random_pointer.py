class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None

        node_to_idx = {}
        arr = []
        cur = head
        head_ = None
        i = 0
        while cur is not None:
            node_to_idx[cur] = i

            cur_ = Node(cur.val, None, None)
            arr.append(cur_)

            cur = cur.next
            i += 1

        cur = head
        i = 0
        while cur is not None:
            if i != len(arr) - 1:
                arr[i].next = arr[i+1]

            if cur.random is not None:
                arr[i].random = arr[node_to_idx[cur.random]]

            cur = cur.next
            i += 1

        return arr[0]


nodes = [[7,None],[13,0],[11,4],[10,2],[1,0]]
nodes = [[1,1],[2,1]]
nodes = [[3,None],[3,0],[3,None]]

head = None
tail = None
arr = []
for val, _ in nodes:
    new = Node(val, None, None)
    arr.append(new)

    if head is None:
        head = new
        tail = new
    else:
        tail.next = new
        tail = new

for i, (_, rand_idx) in enumerate(nodes):
    if rand_idx is not None:
        arr[i].random = arr[rand_idx]

S = Solution()
head_ = S.copyRandomList(head)
cur = head_
arr = []
while cur:
    arr.append(cur)
    cur = cur.next

cur = head_
while cur:
    if cur.random is None:
        print((cur.val, None), end=' ')
    else:
        print((cur.val, arr.index(cur.random)), end=' ')

    cur = cur.next
print()
