class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        n = len(nums)
        for i in range(n):
            nums[i] -= 1

        i = n - 1
        j = n - 1
        while True:
            i = nums[i]
            j = nums[ nums[j] ]

            if i == j:
                break

        i = n - 1
        while i != j:
            i = nums[i]
            j = nums[j]

        return i+1

nums = [1,3,4,2,2]

S = Solution()
print(S.findDuplicate(nums))
