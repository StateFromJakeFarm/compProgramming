class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        nums = [(n, i) for i, n in enumerate(nums)]
        nums = sorted(nums, key=lambda x: x[0])

        i = 0
        j = len(nums) - 1
        while i < j:
            summed = nums[i][0] + nums[j][0]
            if summed == target:
                return [nums[i][1], nums[j][1]]

            if summed < target:
                i += 1
            else:
                j -= 1

S = Solution()

nums = [2,7,11,15]
target = 9
print(S.twoSum(nums, target))
