class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack = []
        for t in tokens:
            if t == '+':
                op2 = stack.pop(-1)
                op1 = stack.pop(-1)
                stack.append(op1 + op2)
            elif t == '-':
                op2 = stack.pop(-1)
                op1 = stack.pop(-1)
                stack.append(op1 - op2)
            elif t == '*':
                op2 = stack.pop(-1)
                op1 = stack.pop(-1)
                stack.append(op1 * op2)
            elif t == '/':
                op2 = stack.pop(-1)
                op1 = stack.pop(-1)
                stack.append(int(op1 / op2))
            else:
                stack.append(int(t))

        return stack.pop(-1)


tokens = ["1","2","+","3","*","4","-"]

S = Solution()
print(S.evalRPN(tokens))
