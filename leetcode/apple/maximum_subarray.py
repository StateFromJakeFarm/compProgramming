class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        overall_max = 0

        running_max = 0
        for n in nums:
            running_max = max(running_max + n, n)
            overall_max = max(overall_max, running_max)

        if overall_max == 0:
            # Subarray can't be empty, so if overall_max is zero, all elements must be negative
            return max(nums)

        return overall_max


S = Solution()

arr = [-2,1,-3,4,-1,2,1,-5,4]
print(S.maxSubArray(arr))
