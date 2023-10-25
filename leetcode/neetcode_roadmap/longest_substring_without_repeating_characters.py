class Solution:
    def lengthOfLongestSubstring(self, chars: str) -> int:
        last_seen = {}
        max_len = 0

        s = 0
        for e in range(len(chars)):
            if chars[e] in last_seen:
                s = max(s, last_seen[ chars[e] ] + 1)

            last_seen[ chars[e] ] = e
            max_len = max(max_len, e - s + 1)

        return max_len


s = "abcabcbb"

S = Solution()
print(S.lengthOfLongestSubstring(s))
