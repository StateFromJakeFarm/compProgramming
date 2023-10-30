class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        C = {}
        for c in s1:
            if c in C:
                C[c] += 1
            else:
                C[c] = 1

        # Populate initial window
        l = len(s1)
        for j in range(l):
            if s2[j] in C:
                C[ s2[j] ] -= 1

        i = 0
        while True:
            # Check if valid
            good = True
            for c in C.keys():
                if C[c] > 0:
                    good = False
                    break
            if good:
                return True

            if i + l >= len(s2):
                # Reached end of string
                break

            # Expell tail
            if s2[i] in C:
                C[ s2[i] ] += 1

            # Ingest head
            if s2[i + l] in C:
                C[ s2[i + l] ] -= 1

            i += 1

        return False


s1 = "ab"
s2 = "eidbaooo"

S = Solution()

print(S.checkInclusion(s1, s2))
