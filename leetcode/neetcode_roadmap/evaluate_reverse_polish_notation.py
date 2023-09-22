from collections import deque
from math import ceil, floor

class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        ops = set(['+', '-', '*', '/'])

        stack = deque()
        for i in range(len(tokens) - 1, -1, -1):
            while (len(stack) >= 3) and (stack[-1] not in ops) and (stack[-2] not in ops) and (stack[-3] in ops):
                # We have 2 numbers and an op
                n1 = stack.pop()
                n2 = stack.pop()
                op = stack.pop()

                if op == '+':
                    ans = n1 + n2
                elif op == '-':
                    ans = n1 - n2
                elif op == '*':
                    ans = n1 * n2
                else:
                    if (n1 < 0) != (n2 < 0):
                        # Answer is negative
                        ans = ceil(n1 / n2)
                    else:
                        # Answer is positive
                        ans = floor(n1 / n2)

                stack.append(ans)

            if tokens[i] in ops:
                stack.append(tokens[i])
            else:
                stack.append(int(tokens[i]))

        # Need to handle statement completed by last token
        while (len(stack) >= 3) and (stack[-1] not in ops) and (stack[-2] not in ops) and (stack[-3] in ops):
            # We have 2 numbers and an op
            n1 = stack.pop()
            n2 = stack.pop()
            op = stack.pop()

            if op == '+':
                ans = n1 + n2
            elif op == '-':
                ans = n1 - n2
            elif op == '*':
                ans = n1 * n2
            else:
                if (n1 < 0) != (n2 < 0):
                    # Answer is negative
                    ans = ceil(n1 / n2)
                else:
                    # Answer is positive
                    ans = floor(n1 / n2)

            stack.append(ans)

        return stack.pop()

tokens = ["2","1","+","3","*"]
tokens = ['4', '13', '5', '/', '+']
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]

S = Solution()
print(S.evalRPN(tokens))
