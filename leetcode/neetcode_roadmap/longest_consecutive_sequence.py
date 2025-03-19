class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0

        longest = 1
        S = set(nums)
        for num in nums:
            if num not in S:
                continue

            l = num
            r = num
            cur_len = 1
            while l-1 in S or r+1 in S:
                if l-1 in S:
                    l -= 1
                    S.remove(l)
                    cur_len += 1

                if r+1 in S:
                    r += 1
                    S.remove(r)
                    cur_len += 1

            longest = max(longest, cur_len)

        return longest

nums = [1,0,1,2]

S = Solution()
print(S.longestConsecutive(nums))
