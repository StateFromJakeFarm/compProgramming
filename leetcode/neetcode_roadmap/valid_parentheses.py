class Solution:
    def get_complement(self, c):
        return {
            ')': '(',
            '}': '{',
            ']': '['
        }.get(c)


    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(c)
            else:
                if len(stack) < 1 or self.get_complement(c) != stack[-1]:
                    return False
                stack.pop(-1)

        return len(stack) == 0
