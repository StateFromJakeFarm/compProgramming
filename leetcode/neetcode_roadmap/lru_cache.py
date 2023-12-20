class ListNode:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.next = None
        self.prev = None


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.map = {}
        self.head = None
        self.tail = None


    def place_front(self, node):
        if node == self.head:
            return

        # Make prev and next point to each other
        if node.next is not None:
            node.next.prev = node.prev
        if node.prev is not None:
            node.prev.next = node.next

        if node == self.tail and node.prev is not None:
            self.tail = node.prev
            self.tail.next = None

        if self.head is not None:
            # Set head's prev to node
            self.head.prev = node
        else:
            # List is empty; set tail too
            self.tail = node

        node.next = self.head
        node.prev = None
        self.head = node


    def get(self, key: int) -> int:
        if key not in self.map:
            return -1

        self.place_front(self.map[key])

        return self.map[key].val


    def put(self, key: int, val: int) -> None:
        if key in self.map:
            # Key is already in list
            self.map[key].val = val
            self.place_front(self.map[key])
        else:
            # Node doesn't exist yet; append to front
            new = ListNode(key, val)
            self.map[key] = new
            self.place_front(new)

        if len(self.map) > self.capacity:
            # We went over capacity; evict LRU
            lru_key = self.tail.key
            self.tail = self.tail.prev
            self.tail.next = None
            del self.map[lru_key]


cache = LRUCache(2)

funcs = ["put","put","get","get","put","get","get","get"]
args = [[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]]
for func, arg in zip(funcs, args):
    if func == 'put':
        cache.put(arg[0], arg[1])
        print(None)
    else:
        print(cache.get(arg[0]))
