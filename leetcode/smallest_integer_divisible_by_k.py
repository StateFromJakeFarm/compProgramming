class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        rem = 1
        i = 1
        while i <= k:
            if rem % k == 0:
                return i

            rem = ((rem % k)*10 + 1) % k

            i += 1

        return -1


S = Solution()

print(S.smallestRepunitDivByK(3))
