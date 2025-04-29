class Solution:
    def findMin(self, nums: list[int]) -> int:
        lo = 0
        hi = len(nums) - 1

        while (lo+1) < hi:
            if nums[lo] < nums[hi]:
                return nums[lo]

            mid = (lo + hi) // 2

            if nums[lo] > nums[mid]:
                # Break is to the left
                hi = mid
            else:
                # Break is to the right
                lo = mid

        # Normally can just return nums[hi] in this case, but in edge case where 
        # len(nums) == 2, need to check
        return min(nums[lo], nums[hi])


nums = [3,4,5,1,2]

S = Solution()
print(S.findMin(nums))
