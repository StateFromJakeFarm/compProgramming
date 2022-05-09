from math import ceil


class Solution:
    def get_combos(self, l1, l2):
        res = []

        for x in l1:
            for y in l2:
                res.append(x + y)
                res.append(y + x)

        return res


    def generateParenthesis(self, n: int):
        l = [['']]

        for i in range(1, n+1):
            cur = [f'({x})' for x in l[i-1]]

            for j in range(1, i):
                k = i - j

                cur += self.get_combos(l[j], l[k])

            l.append(set(cur))

        return list(l[-1])

S = Solution()

res = S.generateParenthesis(5)
print(res)
