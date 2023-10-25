class Solution:
    def __init__(self):
        self.counts = {}


    def get_max(self):
        max_char = None
        max_count = 0
        for char, count in self.counts.items():
            if count > max_count:
                max_char = char
                max_count = count

        return max_char


    def characterReplacement(self, chars: str, k: int) -> int:
        cur_max = chars[0]
        self.counts = {chars[0]: 1}
        s = 0
        for e in range(1, len(chars)):
            if chars[e] not in self.counts:
                self.counts[ chars[e] ] = 1
            else:
                self.counts[ chars[e] ] += 1

            if self.counts[ chars[e] ] > self.counts[cur_max]:
                cur_max = chars[e]

            l = e - s + 1
            if l - self.counts[cur_max] > k:
                # This doesn't work
                self.counts[ chars[s] ] -= 1
                if self.counts[ chars[s] ] == 0:
                    del self.counts[ chars[s] ]

                if chars[s] == cur_max:
                    cur_max = self.get_max()

                s += 1

        return e - s + 1

s = "AABABBA"
k = 1

S = Solution()
print(S.characterReplacement(s, k))
