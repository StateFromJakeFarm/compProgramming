class Solution:
    def __init__(self):
        self.C = {}


    def check(self):
        for count in self.C.values():
            if count > 0:
                return False

        return True


    def minWindow(self, s: str, t: str) -> str:
        for char in t:
            if char in self.C:
                self.C[char] += 1
            else:
                self.C[char] = 1

        i = 0
        j = -1
        min_i = -1
        min_j = 100001
        got_one = False
        while i <= len(s) - len(t) and j < len(s):
            if self.check():
                got_one = True
                if (min_j - min_i) > (j - i):
                    min_i = i
                    min_j = j

                if j - i + 1 == len(t):
                    # Can't get any better
                    return s[i:j+1]

                if s[i] in self.C:
                    self.C[ s[i] ] += 1
                i += 1
            else:
                j += 1
                if j < len(s) and s[j] in self.C:
                    self.C[ s[j] ] -= 1

        if not got_one:
            return ''

        return s[min_i:min_j+1]


s = "ADOBECODEBANC"
t = "ABC"

S = Solution()
print(S.minWindow(s, t))
