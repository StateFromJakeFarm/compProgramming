def lengthOfLongestSubstring(s: str) -> int:
    max_len = 0
    last_seen = {c: -1 for c in s}

    last_repeat = -1
    for i, c in enumerate(s):
        print(s[:i+1], last_seen, last_repeat, max_len)
        max_len = max(max_len, i - max(last_seen[c], last_repeat))

        if c in last_seen:
            last_repeat = max(last_repeat, last_seen[c])

        last_seen[c] = i

    return max_len


print(lengthOfLongestSubstring('abcabcbb'))
print(lengthOfLongestSubstring('bbbbb'))
print(lengthOfLongestSubstring('pwwkew'))
print(lengthOfLongestSubstring('dvdf'))
print(lengthOfLongestSubstring('au'))
