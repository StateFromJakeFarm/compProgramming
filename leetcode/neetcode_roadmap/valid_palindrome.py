import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Why?
        s = re.sub('[^a-z0-9]', '', s, flags=re.IGNORECASE)

        i = 0
        j = len(s) - 1
        while i < j:
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True

S = Solution()
s="Was it a car or a cat I saw?"
print(S.isPalindrome(s))
