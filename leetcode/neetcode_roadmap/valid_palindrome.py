import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        alphanum_only = re.compile('[^a-z0-9]')
        s = alphanum_only.sub('', s)

        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False

            i += 1
            j -= 1

        return True


s = 'A man, a plan, a canal: Panama'

S = Solution()
print(S.isPalindrome(s))
