class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        S = set(nums)

        longest = 0
        for n in nums:
            if n not in S:
                # n has already been included in another "run"
                continue

            S.remove(n)

            lower = n - 1
            while lower in S:
                S.remove(lower)
                lower -= 1
            lower += 1 # Last one we checked DNE

            higher = n + 1
            while higher in S:
                S.remove(higher)
                higher += 1
            higher -= 1 # Last one we checked DNE

            longest = max(longest, higher - lower + 1)

        return longest

S = Solution()

nums = list(range(5000)) + list(range(-12, -10))
print(S.longestConsecutive(nums))
