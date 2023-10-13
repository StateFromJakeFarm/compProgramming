class Solution:
    def findMin(self, nums: list[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if nums[lo] <= nums[mid]:
                if nums[mid] < nums[hi]:
                    # In order
                    hi = mid
                else:
                    # Break is to the right
                    if mid == hi - 1:
                        # Found it
                        return nums[hi]

                    lo = mid
            else:
                # Break is to the left
                if mid == lo + 1:
                    # Found it
                    return nums[mid]

                hi = mid

        return nums[lo]

nums = [3,4,5,1,2]

S = Solution()
print(S.findMin(nums))
