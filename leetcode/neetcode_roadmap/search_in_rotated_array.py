class Solution:
    def search(self, nums: list[int], target: int) -> int:
        lo = 0
        hi = len(nums) - 1
        while True:
            mid = (lo + hi) // 2

            if target == nums[mid]:
                return mid
            if target == nums[lo]:
                return lo
            if target == nums[hi]:
                return hi

            if lo == hi or lo == hi - 1:
                return -1

            if nums[lo] < nums[mid] and nums[mid] < nums[hi]:
                # In order; regular search
                if target < nums[mid]:
                    hi = mid
                else:
                    lo = mid
            elif nums[mid] > nums[hi]:
                # Break is to the right
                if target > nums[mid] or target <= nums[hi]:
                    lo = mid
                else:
                    hi = mid
            else:
                # Break is to the left
                if target > nums[mid] and target <= nums[hi]:
                    lo = mid
                else:
                    hi = mid


nums = [4,5,6,7,8,1,2,3]
target = 8

S = Solution()
print(S.search(nums, target))
