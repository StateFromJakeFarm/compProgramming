class Solution:
    def rec(self, l, o, c):
        if o == self.n and c == self.n:
            self.all.append(''.join(l))
            return

        if o < self.n:
            self.rec(l + ['('], o+1, c)
        if o > c:
            self.rec(l + [')'], o, c+1)


    def generateParenthesis(self, n: int) -> list[str]:
        self.n = n
        self.all = []

        self.rec([], 0, 0)

        return self.all


n = 3

S = Solution()
print(S.generateParenthesis(n))
