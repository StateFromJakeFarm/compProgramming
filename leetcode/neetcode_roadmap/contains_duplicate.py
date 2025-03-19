class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()
        for num in nums:
            if num not in seen:
                seen.add(num)
            else:
                return True

        return False


S = Solution()

nums = [1,2,3,1]

print(S.containsDuplicate(nums))
