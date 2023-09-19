class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start_of_most_recent = -1
        last_seen = {}
        longest = 0

        most_recent_match = ''
        for i, x in enumerate(s):
            if x in last_seen:
                start_of_most_recent = max(start_of_most_recent, last_seen[x])

            l = i - start_of_most_recent

            last_seen[x] = i

            longest = max(longest, l)

        return longest

S = Solution()

s = 'abcabcbb'
print(S.lengthOfLongestSubstring(s))
