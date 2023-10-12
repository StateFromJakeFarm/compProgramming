class Solution:
    def search(self, nums: list[int], target: int) -> int:
        lo = 0
        hi = len(nums) - 1

        while lo <= hi:
            idx = (hi + lo) // 2
            if nums[idx] == target:
                return idx

            if nums[idx] < target:
                lo = idx + 1
            else:
                hi = idx - 1

        return -1


nums = [-1,0,3,5,9,12]
target = 9

S = Solution()

print(S.search(nums, target))
