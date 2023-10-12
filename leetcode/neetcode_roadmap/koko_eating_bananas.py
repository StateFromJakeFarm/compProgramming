from math import ceil

class Solution:
    def getTime(self, k):
        return sum(map(lambda p: ceil(p / k), self.piles))


    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        self.piles = piles

        lo = 1
        hi = max(self.piles)

        min_good_k = float('inf')
        while lo <= hi:
            k = (lo + hi) // 2
            if self.getTime(k) <= h:
                min_good_k = min(min_good_k, k)

                hi = k - 1
            else:
                if k == min_good_k - 1:
                    return min_good_k

                lo = k + 1

        return lo


piles = [3,6,7,11]
h = 8

piles = [30,11,23,4,20]
h = 5

piles = [30,11,23,4,20]
h = 6

S = Solution()

print(S.minEatingSpeed(piles, h))
