class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        max_diff = 0
        min_price = 10001
        for p in prices:
            min_price = min(min_price, p)
            max_diff = max(max_diff, p - min_price)

        return max_diff


prices = [7,1,5,3,6,4]

S = Solution()
print(S.maxProfit(prices))
