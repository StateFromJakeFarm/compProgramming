class Solution:
    def minimizeArrayValue(self, nums: list[int]) -> int:
        from math import ceil

        max_min = 0
        running_sum = 0
        for i, x in enumerate(nums):
            running_sum += x
            avg = running_sum / (i+1)
            max_min = max(max_min, avg)

        return ceil(max_min)
                


nums = [4,7,2,2,9,19,16,0,3,15]

S = Solution()
print(S.minimizeArrayValue(nums))
