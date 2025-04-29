from math import ceil


class Solution:
    def total_hours(self, k):
        total = 0
        for x in self.piles:
            total += ceil(x/k)

        return total


    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        self.piles = piles

        lo = 1
        hi = max(piles)
        k = hi
        while lo <= hi:
            mid = (lo + hi) // 2

            mid_hours = self.total_hours(mid)
            if (mid_hours <= h) and (mid < k):
                # Found solution
                k = mid

            if mid_hours <= h:
                # May be able to go slower
                hi = mid - 1
            else:
                lo = mid + 1

        return k


S = Solution()

piles = [1,1,1,999999999]
h = 10

print(S.minEatingSpeed(piles, h))
