class Solution:
    def romanToInt(self, s: str) -> int:
        val_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        total = 0
        prev = -1
        for cur in reversed(s):
            cur = val_map[cur]

            if cur < prev:
                total -= cur
            else:
                total += cur

            prev = cur

        return total

S = Solution()

print(S.romanToInt('MCMXCIV'))
