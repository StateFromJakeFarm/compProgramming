class Solution:
    def minimizeArrayValue(self, nums: list[int]) -> int:
        from math import ceil

        max_min = 0
        running_sum = 0
        for i, x in enumerate(nums):
            running_sum += x
            avg = running_sum / (i+1)

            # The worst distribution of weight we can achieve across the whole set
            # of numbers is the worst distribution of weight to the left of any
            # one number.  Because we can only shift weight from right to left,
            # the average weight for positions [0...i] is the best-case storage
            # scenario for elements [0...i].
            max_min = max(max_min, avg)

        return ceil(max_min)
                


nums = [4,7,2,2,9,19,16,0,3,15]

S = Solution()
print(S.minimizeArrayValue(nums))
