import re


class Solution:
    def encode(self, strs: list[str]) -> str:
        num_regex = re.compile('[0-9]')

        out = []
        for s in strs:
            e = []
            for i, c in enumerate(s):
                if i == 0 and num_regex.match(c) is not None:
                    # First character is a number or escape character
                    e.extend(['`', c])
                elif c == '`':
                    e.extend(['`', '`'])
                else:
                    e.append(c)

            out.append(str(len(s)) + ''.join(e))

        return ''.join(out)


    def decode(self, s: str) -> list[str]:
        num_regex = re.compile('[0-9]')
        out = []

        l = 0
        cur = []
        for i, c in enumerate(s):
            if l <= 0:
                # We should be getting length of next string
                if num_regex.match(c) is not None:
                    # We're still getting more of the length number
                    if len(cur) == 0 and c == '0':
                        # Empty string
                        out.append('')
                    else:
                        cur.append(c)
                else:
                    # We got the whole length number
                    l = int(''.join(cur))

                    if c != '`':
                        cur = [c]
                        l -= 1

                        if l == 0:
                            # Edge case for length 1 with no special characters
                            out.append(cur[0])
                            cur = []
                    else:
                        cur = []
            else:
                # We have more to consume
                if c == '`' and i > 0 and s[i-1] != '`':
                    # Ignore the escape character and keep moving
                    continue

                cur.append(c)
                l -= 1

                if l == 0:
                    # We ate the whole word
                    out.append(''.join(cur))
                    cur = []

        return out


strs = ['`h', "", 'ha']

S = Solution()
meme = S.encode(strs)
print(meme)
print(S.decode(meme))
