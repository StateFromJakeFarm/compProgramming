class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        best = 0
        buy = 10001
        for p in prices:
            buy = min(buy, p)
            best = max(best, p - buy)

        return best

S = Solution()

prices = [7,1,5,3,6,4]
print(S.maxProfit(prices))
