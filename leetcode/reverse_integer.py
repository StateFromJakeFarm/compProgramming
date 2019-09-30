import math

class Solution:
    def reverse(self, x: int) -> int:
        is_neg = x < 0
        x = abs(x)
        x = int(''.join([d for d in reversed(str(x))]))

        if (x > math.pow(2, 31)-1 or x < -math.pow(2, 31)):
            return 0

        return -1*x if is_neg else x

S = Solution()

print(S.reverse(123))
