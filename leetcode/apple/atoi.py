import re


class Solution:
    def myAtoi(self, s: str) -> int:
        match_obj = re.search('^\s*([\-\+]{0,1}[0-9]+)', s)
        if match_obj is None:
            return 0

        s = match_obj.group(1)

        sign = 1
        if s[0] in ['-', '+']:
            if s[0] == '-':
                sign = -1

        match_obj = re.search('([1-9][0-9]*)', s)
        if match_obj is None:
            return 0
        s = match_obj.group(1)

        num = sign * sum([int(d) * 10**i for i, d in enumerate(reversed(s))])
        if num > 2147483647:
            return 2147483647
        if num < -2147483648:
            return -2147483648

        return num


S = Solution()
print(S.myAtoi("00000-42a1234"))
