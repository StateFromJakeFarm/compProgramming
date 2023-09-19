class Solution:
    def isValid(self, s: str) -> bool:
        comps = {
            '(': ')',
            '[': ']',
            '{': '}'
        }

        stack = []
        for x in s:
            if len(stack) == 0:
                if x not in comps:
                    # Starts with a close
                    return False
                else:
                    stack.append(x)
            else:
                top = stack[-1]
                if comps[top] == x:
                    # Match
                    stack.pop()
                elif x not in comps:
                    # Closing the wrong kind of bracket
                    return False
                else:
                    # Opening another
                    stack.append(x)

        return len(stack) == 0


S = Solution()

s = "[(]"
print(S.isValid(s))
