class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        n = 0

        total = 0
        prefix_sums = {0: 1}
        for x in nums:
            total += x
            n += prefix_sums.get(total - k, 0)
            if total in prefix_sums:
                prefix_sums[total] += 1
            else:
                prefix_sums[total] = 1

        return n


arr = [-1, 1, 0]
k = 0

S = Solution()
print(S.subarraySum(arr, k))
