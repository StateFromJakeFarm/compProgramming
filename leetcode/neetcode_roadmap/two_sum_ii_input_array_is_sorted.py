class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        i = 0
        j = len(nums) - 1
        while nums[i] + nums[j] != target:
            summed = nums[i] + nums[j]
            if summed < target:
                i += 1
            else:
                j -= 1

        return [i+1, j+1]


numbers = [2,7,11,15]
target = 9

numbers = [2, 3, 4]
target = 6

numbers = [-1, 0]
target = -1

S = Solution()
print(S.twoSum(numbers, target))
