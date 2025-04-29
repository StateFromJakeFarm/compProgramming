class Solution:
    def __init__(self):
        self.solutions = []


    def level(self, max_open, stack, n_open):
        if len(stack) == max_open*2:
            if n_open == 0:
                self.solutions.append(stack)

            return

        if n_open < max_open:
            self.level(max_open, stack + ['('], n_open + 1)

        if n_open > 0:
            self.level(max_open, stack + [')'], n_open - 1)


    def generateParenthesis(self, n: int) -> list[str]:
        self.level(n, ['('], 1)

        return [''.join(x) for x in self.solutions]


S = Solution()

print(S.generateParenthesis(4))
