from collections import deque

class MinStack:
    def __init__(self):
        # Holds (value, minimum below this value)
        self.stack = deque()


    def push(self, val: int) -> None:
        if len(self.stack) == 0:
            self.stack.append((val, 2**31))
        else:
            top, min_below_top = self.stack[-1]
            self.stack.append((val, min(top, min_below_top)))


    def pop(self) -> None:
        self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return min(self.stack[-1])


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

s = MinStack()
s.push(-2)
s.push(0)
s.push(-3)
print(s.getMin())
s.pop()
print(s.top())
print(s.getMin())
