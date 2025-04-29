class Solution:
    def search(self, nums: list[int], target: int) -> int:
        if len(nums) in [1, 2]:
            try:
                return nums.index(target)
            except:
                return -1

        lo, hi = 0, len(nums) - 1
        while (lo + 1) < hi:
            mid = (lo + hi) // 2
            if nums[mid] == target:
                return mid

            if nums[lo] > nums[mid]:
                # Break is to the left

                if target >= nums[lo] or target <= nums[mid]:
                    # Go left
                    hi = mid - 1
                else:
                    lo = mid + 1
            elif nums[hi] < nums[mid]:
                # Break is to the right

                if target >= nums[mid] or target <= nums[hi]:
                    # Go right
                    lo = mid + 1
                else:
                    hi = mid - 1
            else:
                # Ascending order; regular binary search
                if nums[mid] < target:
                    lo = mid + 1
                else:
                    hi = mid - 1

        if nums[lo] == target:
            return lo
        if nums[hi] == target:
            return hi

        return -1


nums = [4,5,6,7,0,1,2]
target = 0

S = Solution()
print(S.search(nums, target))
